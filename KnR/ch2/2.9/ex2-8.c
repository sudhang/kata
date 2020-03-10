/* Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions */

#include <stdio.h>

#define MAXLINE 15
#define NUMDIGITS 8 * sizeof(int)
#define NSHIFT 3

unsigned int rightrot(unsigned int x, int n)
{
  //return ((x & ~(~0 << n)) << (NUMDIGITS - n)) | (x >> n) ;
  return (x << (NUMDIGITS - n)) | (x >> n) ;  //From "Hacker's Delight" First Ed. section 2-14 pg 23
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
  printf("NUMDIGITS: %d\n", NUMDIGITS);

  while ( (len = getline(line, MAXLINE)) > 0) {
    num = atoi(line);

    printf("\nThe new number is: %u\n", rightrot(num, NSHIFT));
  }
}
