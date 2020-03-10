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

/* undef: remove (name, defn) from hashtab */
void undef(char *name, char *defn)
{
  struct nlist *np, *p;

  if((np = lookup(name) != NULL)) {
    for (p = hashtab[hash(name)]; p->next != np; np = np->next)
      ;
    p->next = np->next;
    free(np);
  }
  else printf("(%s, %s) not in hashtab\n", name, defn);
}
