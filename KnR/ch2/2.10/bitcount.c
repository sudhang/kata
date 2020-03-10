/*  bitcount: count 1 bits in x */

#include <stdio.h>

#define MAXLINE 10

int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)  {
    if (x & 01)
      b++;
  }
  return b;
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
  int len;
  unsigned num;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0) {
    num = atoi(line);

    printf("\nThe number of 1s in the binary form of %d is: %i\n", num, bitcount(num));
  }
}
