/* Count the number of lines, blanks, and tabs entered */

#include <stdio.h>

main ()
{
	int c,nb,nt,nl;

	nl = nb = nt = 0;
	while ( (c = getchar()) != EOF )	{
		switch ( c ) {
			case '\n':	nl++ ;
			case '\t':	nb++ ;
			case ' ':		nb++ ;
		}
	}

	printf( "The number of lines entered is %d\nThe number of blanks entered is %d\nThe number of tabs entered is %d\n" , nl , nb , nt );
}
			
