#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')   /* Skip leading whitespace */
    ;
  s[1] = '\0';

  i = 0;

  if (isalpha(c))  {      /* the character may be a single character, or part of a word */
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    return TOKEN;
  }

  if(!isdigit(c) && c != '.' && c != '-' && c != '+') /* an operand, other than maybe + or - */
     return c;                 

  if(c == '+' || c == '-')  {
    if (isspace(s[++i] = c = getch()))  {   /* it is an operand + or - */
      ungetch(c);   
      return s[0];
    }
  }

  while(isdigit(s[++i] = c = getch()))
    ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}
