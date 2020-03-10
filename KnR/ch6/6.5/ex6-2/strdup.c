#include "ex6-2.h"

/* make a duplicate of s, only up to n characters */
char *strNdup(char *s, int n)
{
  char *p;
  p = (char *) malloc(n + 1);   /* +1 for '\0' */
  if (p != NULL)
    strncpy(p, s, n);
  return p;
}
