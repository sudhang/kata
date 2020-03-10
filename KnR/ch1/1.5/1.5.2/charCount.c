/* Program to count the number of characters entered */

#include <stdio.h>

main()
{
	int nc;

	for ( nc = 0 ; ( getchar() != EOF ) ; nc++ )
		;

	printf( "No. of Characters Entered: %d\n" , nc );
}
