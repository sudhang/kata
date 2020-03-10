#include "dcl.h"
int prevTokenExists = 0;
int gettoken(void)    /* return next token */
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  if (prevTokenExists == 1)  {
    prevTokenExists = 0;
    return tokentype;
  }

  while ((c = getch()) == ' ' || c == '\t')
    ;

  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else  {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[')  {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c))  {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}