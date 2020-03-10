/* Write the function itob(n,s,b) that converst the integet n into a base b character representation in the string
 * s. In particular itob(n,s,16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define NUM 16
#define BASE 16

void reverse(char s[]) 
{
  int c, i, j;
  for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int b) 
{
  int i, sign;
  sign = n;
  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    if ( (n % b) < 10 )
      s[i++] = n % b + '0';
    else s[i++] = n % b - 10 + 'A';
  } while ( n /= b );

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

main ()
{
  int len, num;
  char line[MAXLINE];

  itoa(NUM,line,BASE);
  printf("The number is %d\n",NUM);
  printf("The base to use is %d\n",BASE);
  printf("The string is: %s\n",line);
}
