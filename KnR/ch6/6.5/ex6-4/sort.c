#include "btree.h"

void sort(struct outarray *O, int len)
{
  int i, j, k;
  struct outarray tmp;

  for (i = 1; i < len; i++) {
    tmp.count = O[i].count;
    tmp.word = (char *) malloc(sizeof(char));
    strcpy(tmp.word, O[i].word);
    j = i - 1;
    while (j >= 0 && O[j].count < tmp.count) {
      O[j+1].count = O[j].count;
      strcpy(O[j+1].word, O[j].word);
      j--;
    }
    O[j+1].count = tmp.count;
    strcpy(O[j+1].word, tmp.word);
  }
}
