/* Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field
 * width; the converted number must be padded with blanks on the left if necessary to make it wide enough
 */

#include <string.h>
#include <stdio.h>

#define MAXLINE 100
#define NUM 10
#define WIDTH 6


void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i<j ; ++i , --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int w)
{
  int i, sign, len;
  if ((sign = n ) < 0)
    n = -n;

  i = 0;

  do {    /* generate digits in reverse order */
    s[i++] = n % 10 + '0';
  } while ( (n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  len = strlen(s);
  printf("strlen = %d\n",len);
  printf("w - strlen = %d\n", (w - len));

  /* Pad with blanks */
  for (i = len; i < w - len + 1; ++i)
    s[i] = ' ';

  s[i] = '\0';
  reverse(s);
}

main ()
{
  int len, num;
  char line[MAXLINE];

  itoa(NUM,line,WIDTH);
  printf("The string is: %s\n",line);
}

