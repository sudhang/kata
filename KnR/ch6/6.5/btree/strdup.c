#include "btree.h"

/* make a duplicate of s */
char *strdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s) + 1);   /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}
