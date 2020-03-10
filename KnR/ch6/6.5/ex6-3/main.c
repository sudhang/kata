#include "btree.h"

/* word frequency count */
main()
{
  struct tnode *root;
  char word[MAXWORD];
  int ltran = NO, lnum = 1;

  root = NULL;
  while (getword(word, MAXWORD, &ltran) != EOF)   {
    if (isalpha(word[0]))
      root = addtree(root, word, lnum);
    if (ltran)  {
      ltran = NO;
      lnum++;
    }
  }
  treeprint(root);
  return 0;
}
