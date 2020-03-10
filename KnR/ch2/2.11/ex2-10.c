/* Rewrite teh function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else 
 */
#include <stdio.h>
#define MAXLINE 100

int lower (int c)
{
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}


main ()
{
  int len,i;
  char string[MAXLINE];

  while ( (len = getline(string, MAXLINE)) > 0 )  {
    printf("\nYou Entered: %s",string);

    for (i = 0; i< len; ++i)  {
      string[i] = lower(string[i]);
    }

    printf("\nLower case: %s",string);
  }
}
