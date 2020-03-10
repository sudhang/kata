/* Write a program to print a histogram of frequencies of characters in input */

#include <stdio.h>

#define BVLEN 255   /* The number of characters in the currently used character set */

main ()
{
  int c, i, j, bv[BVLEN];

  /* Clear the bit vector */
  for ( i = 0 ; i < BVLEN ; ++i )
    bv[i] = 0;

  while ( (c = getchar()) != EOF )
      ++bv[c];

  /* Print the histogram */
  putchar('\n');
  for ( i = 0 ; i < BVLEN ; ++i ) {
    if ( bv[i] != 0 ) {
      printf("%c: ", i);
      for ( j = 0 ; j < bv[i] ; ++j ) {
        putchar('-');
      }
      putchar('\n');
    }
  }
}
