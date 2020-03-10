#include "sort.h"

/* strcpy: copy t to s; pointer version 1 */
#include "sort.h"

void strcpy(char *s, char *t)
{
  while (*s++ = *t++)
    ;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN]; 

  nlines = 0; 
  while ((len = getline(line, MAXLEN)) > 0)
    if ( nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else  {
      line[len-1] = '\0';   /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
