#include "btree.h"

/* treeprint: in-order print of tree p */
void getcounts(struct tnode *p, struct outarray *O, int *len)
{
  if (p != NULL)  {
    getcounts(p->left, O, len);
    O[*len].word = (char *) malloc(sizeof(char));
    strcpy(O[*len].word, p->word);
    O[*len].count = p->count;
    *len += 1;
    getcounts(p->right, O, len);
  }
}
