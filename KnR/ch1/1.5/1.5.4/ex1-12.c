/* Write a program that prints its input one word per line */

#include <stdio.h>
#define IN 1
#define OUT 0

main ()
{
  int c,state = IN;

  while ( (c = getchar()) != EOF )  {
    if ( (c == ' ') || (c == '\t') )  {
      if ( state == IN )    /* change to OUT if IN */
        state = OUT;        /* remain OUT if OUT   */
    } 

    else  {
      if ( state == OUT ) {
        putchar('\n');
        state = IN;
      }
      putchar(c);
    }
  }
}
