#include "sort.h"

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  while (nlines-- > 0)  {
    printf("%s\n", *lineptr++);
  }
}
