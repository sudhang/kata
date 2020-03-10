/* C program that copies its input to output, a character at a time */

#include <stdio.h>

main ()
	{
		int c;
		while ( (c = getchar()) != EOF )
			putchar(c);
	}
