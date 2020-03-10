/* Write a program that prints its input one word per line */

#include <stdio.h>
#define IN 1
#define OUT 0

main ()
{
  int c,state = OUT;

  while ( (c = getchar()) != EOF )  {
    if ( (c == ' ') || (c == '\t') )
      putchar('\n');  
    else  
      putchar(c);
  }
}
