#include "tbl.h"

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;
  for (np = hashtab[hash(s)]; np; np = np->next)
    if(strcmp(s, np->name) == 0)
      return np;                /* found */
  return NULL;                  /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name)) == NULL) {   /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if(np == NULL || (np->name = Strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else      /* already exists in table */
    free((void *) np->defn);    /* free the previous defn */
  if((np->defn = Strdup(defn)) == NULL)
    return NULL;
  return np;
}

/*lookup: look for s in hashtab*/
void undef(char *s)
{
  struct nlist *np1, *np2;
  if((np1 = lookup(s)) == NULL)
    return;
  for (np1 = np2 = hashtab[hash(s)]; np1; np2 = np1, np1 = np1->next) {
    if(strcmp(s, np1->name) == 0) {
      if(np1 == np2)
        hashtab[hash(s)] = np1->next;
      else
        np2->next = np1->next;
    }
    free(np1->name);
    free(np1->defn);
    free(np1);
    return;
  }
}

