#include "ex6-2.h"

/* getword: get next word or character from the input */
int getword(char *word, int lim)
{
  int c;
  char *w = word;

  while (isspace(c = getch()))                /* ignore leading blanks and underscores */
    ;

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c))  {
    if (c == '/')   {
      if ( (c = getch()) == '*' ) {                       /* it is the start of a comment */
        while ( (c = getch()) )                           /* skip the comment string      */
          if (c == '*' && getch() == '/')                 /* end of comment string        */
            break;
      }
      else ungetch(c);
    }
    else if (c == '"')  {                                 /* it is the start of a string constant */
      while ((c = getch()) != '"')                        /* skip string constant                 */
        ;
    }
    else if (c == '_')  {
      while (isalnum(getch()))
          ;
    }
    else if ( c == '#' )  {
      while ( getch() != '\n' )
        ;
    }
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
