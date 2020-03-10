/* getbits: get n bits from position p */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10
#define POS 2
#define NUMDIGITS 2

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
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
  int len, num;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0 )  {
    num = atoi(line);

    printf("\nThe number from the bits got is: %u\n", getbits(num,POS,NUMDIGITS));
  }
}
