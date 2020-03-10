#include "ex6-2.h"

/* add an element to the list after the tail */
void addwordlist(char *string, struct wordnode *head)
{
  struct wordnode *p, *tmp;
  tmp = (struct wordnode *) malloc(sizeof(struct wordnode));
  if (tmp != NULL)  {
    tmp->word = (char *) malloc(strlen(string));
    strcpy(tmp->word, string);
    tmp->next = NULL;
    if (head)  {
      for (p = head; p->next; p = p->next)
        ;
      p->next = tmp;
    }
    else 
      head = tmp;
  }
  else printf("could not create temporary pointer for string: %s\n", string);
}

/* addtypetree: add a node with w, at or below p */
struct typenode *addtypetree(struct typenode *p, char *w, int nchars)
{
  int cond;
  if (p == NULL)  { /* a new word type has arrived */
    p = talloc();   /* make a new node in the tree */
    /*printf("%d \n", strNdup(w, nchars));*/
    p->wordtype = strNdup(w, nchars);
    p->words = (struct typenode *) malloc(sizeof(struct typenode));
    addwordlist(w, p->words);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strncmp(w, p->wordtype, nchars)) == 0) {  /* a word type is reencountered */
    p->count++;
    addwordlist(w, p->words);
  }
  else if (cond < 0)  /* move to the left subtree */
    p->left = addtypetree(p->left, w, nchars);
  else
    p->right = addtypetree(p->right, w, nchars);
  return p;
}
