/* itoa: convert n to characters in s */
#include <string.h>
#include <stdio.h>

#define MAXLINE 100
#define NUM 3456


void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i<j ; ++i , --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  if ((sign = n ) < 0)
    n = -n;

  i = 0;

  do     /* generate digits in reverse order */
    s[i++] = n % 10 + '0';
  while ( (n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

main ()
{
  int len, num;
  char line[MAXLINE];

  itoa(NUM,line);
  printf("The string is: %s\n",line);
}
