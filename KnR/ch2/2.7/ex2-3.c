/* Write the function htoi(s) which converts a string of hexadecimal digits
 * including an optional 0x or 0X) into its equivalent integer value. The allowable
 * digits are 0 through 9, a through f and A through F
 */
#include <stdio.h>

#define MAXLINE 10

int getline(char s[], int lim);

int htoi(char s[])
{
  int i, num = 0;

  for (i = 0; s[i] != '\0' ; ++i) {
    if ( s[i] >= '0' && s[i] <= '9' )
      num = 16*num + (s[i] - '0');
    else if ( s[i] >= 'A' && s[i] <= 'F' )
      num = 16*num + ( (s[i] - 'A') + 10 );
    else if ( s[i] >='a' && s[i] <= 'f' )
      num = 16*num + ( (s[i] -'a') + 10);
  }

  return num;
}

main()
{
  int len, num, i;
  char hexnum[MAXLINE];

  while ( ( len = getline(hexnum, MAXLINE) ) > 0 )  {
   printf("The string is: %s\n",hexnum);
   printf("The decimal equivalent of %s is %d\n",hexnum, htoi(hexnum));
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
