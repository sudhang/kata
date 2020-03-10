/* Write a function invert(x,p,n) that returns x with the n bits that begin at position
 * p inverted (i.e., 1 changed to 0 and vice versa) leaving the others unchanged.
 */

#include <stdio.h>

#define MAXLINE 15
#define POS 6
#define NUMDIGITS 4

unsigned invert(unsigned x, int p, int n)
{
  return (~x & (~(~0 << n) << (p - n + 1)))|(x & ~(~(~0 << n) << (p - n + 1)));
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

main()
{
  unsigned int len, num;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0 )  {
    num = (unsigned) atoi(line);

    printf("\nThe number from the bits got is: %u\n", invert(num,POS,NUMDIGITS));
  }
}
