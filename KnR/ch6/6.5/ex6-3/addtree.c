#include "btree.h"

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int lnum)
{
  int cond;

  if (p == NULL)  { /* a new word has arrived */
    p = talloc();   /* make a new node in the tree */
    p->word = Strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
    p->lines[p->count-1] = lnum;
  } else if ((cond = strcmp(w, p->word)) == 0) {  /* a word is reencountered */
    p->count++;
    p->lines[p->count-1] = lnum;
  }
  else if (cond < 0)  /* move to the left subtree */
    p->left = addtree(p->left, w, lnum);
  else
    p->right = addtree(p->right, w, lnum);
  return p;
}
