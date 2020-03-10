#include "ex6-2.h"

/* treeprint: in-order print of tree p */
void treeprint(struct typenode *p)
{
  if (p != NULL)  {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->wordtype);
    struct wordnode *q;
    if(p->words)  {
      q = p->words;
      while(q->next)  {
        q = q->next;
        printf("\t%s\n", q->word);
      }
    }
    treeprint(p->right);
  }
}

/* word frequency count */
main()
{
  struct typenode *root;
  char word[MAXWORD];
  int nchars = 3;

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtypetree(root, word, nchars);
  treeprint(root);
  return 0;
}
