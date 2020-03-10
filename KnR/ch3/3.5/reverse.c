/* reverse: reverse a string s in place */

#include <stdio.h>

#define MAXLINE 100

void reverse (char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; ++i, --j)   {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
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

main()
{
  int len;
  char line[MAXLINE];

  while ( (len = getline(line,MAXLINE)) > 0)  {
    printf("\nThe reversed line: %s\n",line);
  }
}
