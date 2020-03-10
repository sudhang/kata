/* print the last n lines of input */
#include "ex5-13.h"

void tail(char *lineptr[],int totalLines, int linesToShow)
{
  linesToShow = linesToShow  > totalLines ? totalLines : linesToShow;
  while (--linesToShow >= 0)  {
    printf("%s\n", lineptr[totalLines - linesToShow - 1]);
  }
}

