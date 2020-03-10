/* Count the number of lines entered */

#include <stdio.h>

main ()
{
	int c,nl;

	nl = 0;
	while ( (c = getchar()) != EOF )	{
		if ( c == '\n' )	
			nl++;
	}

	printf( "The number of lines entered is %d\n" , nl );
}
			
