#include "btree.h"

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL)  {
    int i;
    treeprint(p->left);
    printf("%4d %10s: ", p->count, p->word);
    for (i = 0; i < p->count; i++) {
      printf("%3d, ", p->lines[i]);
    }
    printf("\n");
    treeprint(p->right);
  }
}
