/* atoi: convert string s to an integer */

#include <stdio.h>

#define MAXLINE 10
int atoi (char s[])
{
  int i, n = 0;

  for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 *n + (s[i] - '0');
  return n;
}

main()
{
  int len, i;
  char numstring[MAXLINE];

  while ( ( len = getline(numstring, MAXLINE) ) > 0 )  {
   printf("The string is: %s\n",numstring);
   printf("The decimal equivalent of %s is %d\n",numstring, atoi(numstring));
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
