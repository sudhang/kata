/* Write a program to copy its input to output, replacing each string
 * of one or more blanks by a single blank */

#include <stdio.h>

main ()
{
  int c, flag = 0;

  while ( (c = getchar()) != EOF )  {
    if ( c == ' ' ) {             /* Part of a string of blanks */
      flag = 1;
    }
    else if ( flag == 1 ) {       /* Non-blank preceded by a string of blanks */
      putchar(' ');
      putchar(c);
      flag = 0;
    }
    else  {                       /* Non-blank NOT preceded by a string of blanks */
      putchar(c);
    }
  }

}
