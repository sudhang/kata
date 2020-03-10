/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the right most n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>

#define POS 6
#define NUMBITS 4
#define MAXLINE 10

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x & ((~0 << (p + 1)) | (~(~0 << (p - n + 1))))) | (~(~0 << n) & y) << (p - n + 1);
}

int getline(char s[], int lim);

main()
{
  int len, num1, num2;
  char line1[MAXLINE], line2[MAXLINE];

  while ( (len = getline(line1, MAXLINE)) > 0) {
    num1 = atoi(line1);

    getline(line2, MAXLINE);
    num2 = atoi(line2);

    printf("\nThe new number is: %d\n", setbits(num1, POS, NUMBITS, num2));
  }
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}
