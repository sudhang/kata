#include "btree.h"

/* word frequency count */
main()
{
  struct tnode *root;
  char word[MAXWORD];
  struct outarray O[MAXWORD];
  int len = 0, i;

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  getcounts(root, O, &len);
  sort(O, len);
  for (i = 0; i < len; i++) {
    printf("%d %s\n", O[i].count, O[i].word);
  }
  return 0;
}
