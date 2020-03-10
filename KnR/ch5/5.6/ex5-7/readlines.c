#include "sort.h"

/* strcpy: copy t to s; pointer version 1 */
#include "sort.h"

void strcpy(char *s, char *t)
{
  while (*s++ = *t++)
    ;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *buf)
{
  int len, nlines;
  char *p, line[MAXLEN]; 

  nlines = 0; 
  p = buf;
  while ((len = getline(line, MAXLEN)) > 0) {
    if ( nlines >= maxlines )
      return -1;
    else  {
      line[len-1] = '\0';   /* delete newline */
      strcpy(p, line);
      *(lineptr + nlines) = p;
      nlines++;
    }
    p += len;
  }
  return nlines;
}
