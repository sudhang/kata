/* Write the program tail which prints the last n lines of 
 * its input. By default, n is 10, let us say, but it can be changed by 
 * an optional argument, so that
 *      tail -n
 * prints the last n lines. The program should behave rationally no matter how unreasonable the input or
 * the value of n. Write the program so that it makes the best use of available storage; lines should be stored
 * as in the sorting program of section 5.6, not in a two-dimensional array of fixed size
 */
#include "ex5-13.h"
#include <stdlib.h>

main(int argc, char **argv)
{
  int nlines, linesToShow = DEFLINES;     /* number of input lines read */

  while (--argc > 0 && **++argv == '-')  {
    /*switch (*++(*argv))   {
      case '0': 
      case '1': 
      case '2': 
      case '3': 
      case '4': 
      case '5': 
      case '6': 
      case '7': 
      case '8': 
      case '9': 
        linesToShow = **argv - '0';
        break;
      default: 
        printf("invalid option: -%c\n", **argv);
        return;
    }
    */
    linesToShow = atoi(++(*argv));
  }

  if (argc != 0)  {
    printf("Usage: ./ex5-13 -n\n");
    return;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >=0 )
    tail(lineptr, nlines, linesToShow);
}
