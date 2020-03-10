/* Write a program to print a histogram of the lengths of words in its input */

#include <stdio.h>

#define MAX 5   /* The maximum word-length we expect to encounter */
#define IN 1
#define OUT 0

main ()
{
  int c, i, j, len = 0, state = OUT, histarray[MAX];

  /* Clear histarray */
  for ( i = 0; i < MAX ; ++i )  {
    histarray[i] = 0;
  }

  while ( (c = getchar()) != EOF)  {
    if ( ((c == ' ') || (c == '\t') || (c == '\n') ) && ( state == IN ) )  {
          state = OUT;
          ++histarray[len-1];
          len = 0;
    }

    else  {
      len++;
      if ( state == OUT )  {
        state = IN;
      }
    }
  }

  /* Print the Array */
  for ( i =0 ; i < MAX ; i++ )  {
    printf("%d\t",histarray[i]);
  }
  printf("\n\n");

  /* Print the histogram with horizontal bars */
  printf("Horizontal histogram: \n\n");
  for ( i = 0 ; i < MAX ; i++ ) {
    printf("%d ", (i+1) );
    for ( j = 0 ; j < histarray[i] ; j++ ) {
      printf("- ");
    }
    printf("\n");
  }
  /* A Footer */
  printf(" ");
  for ( i = 0 ; i < MAX ; i++ )
    printf(" %d", (i + 1) );

  /* Print the histogram with vertical bars */
  printf("\nVertical histogram: \n\n");
  for ( i = (MAX - 1) ; i >= 0 ; --i ) {
    printf("%d ", (i + 1) );
    for ( j = 0 ; j < MAX ; ++j ) {
      if ( histarray[j] <= i )
        printf("  ");
      else printf("| ");
    }
    printf("\n");
  }
  /* A footer */
  printf(" ");
  for ( i = 0 ; i < MAX ; i++ )
    printf(" %d", (i + 1) );

  printf("\n");
}
