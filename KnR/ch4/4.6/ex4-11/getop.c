#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;
  static int buf = EOF; /* next free position in buf */

  if (buf == EOF || isspace(buf))
    while((s[0] = c = getchar()) == ' ' || c == '\t')
      ;
  else
    s[0] = c = buf;
  buf = EOF;

  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getchar()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getchar()))
      ;
  s[i] = '\0';
  if(c != EOF)
    buf = c;
  return NUMBER;
}
