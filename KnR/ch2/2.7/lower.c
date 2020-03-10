/* lower: convert c to lowercase; ASCII only
 */
#include <stdio.h>

#define MAXLINE 100

char lower(char c)
{
  if (c >= 'A' && c <= 'Z')
    return c += 'a' - 'A';
  else return c;
}

char upper(char c)
{
  if (c >= 'a' && c <= 'z')
    return c -= 'a' - 'A';
  else return c;
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

    for (i = 0; i< len; ++i)  {
      string[i] = upper(string[i]);
    }

    printf("\nUpper case: %s",string);
  }
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
