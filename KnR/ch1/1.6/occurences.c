/* Counts the number of occurrences of each digit, of white space characters, and of all other characters */

#include <stdio.h>

main ()
{
  int c, i, nwhite, nother, ndigit[10];

  nwhite = nother = 0;

  for ( i = 0 ; i < 10 ; ++i ) 
    ndigit[i] = 0;

  while ( (c = getchar()) != EOF )  {
    if ( (c >= '0') && (c <= '9') )
      ++ndigit[c-'0'];
    else if ( c == ' ' || c == '\n' || c == '\t' )
      ++nwhite;
    else
      ++nother;
  }

  printf("No of whitespace characters: %d\n",nwhite);
  printf("No of digits: \n");
  for ( i = 0 ; i < 10 ; ++i )
    printf("Digit %d - %d\n",i,ndigit[i]);
  printf("No of other characters: %d\n",nother);
}
