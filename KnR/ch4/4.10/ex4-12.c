/* itoa: convert n to characters in s */
#include <string.h>
#include <stdio.h>

#define MAXLINE 100
#define NUM 242134


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
  static int i = 0;
  if (n < 0)  {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10)
    itoa( (n / 10), s );

  s[i++] = (n % 10) + '0';
}

main ()
{
  int len, num;
  char line[MAXLINE];

  itoa(NUM,line);
  printf("The string is: %s\n",line);
  printf("The string's length is: %d\n",strlen(line));
}
