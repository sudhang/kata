/* atoi: convert s to integer; version 2*/

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

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

int atoi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); ++i)   //Skip whitespace
    ;

  sign = (s[i] == '-') ? -1 : 1;    

  if (s[i] == '+' || s[i] == '-') //Skip sign
    ++i;

  for (n = 0; isdigit(s[i]); ++i)
    n = 10*n + (s[i] - '0');

  return sign*n;
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
