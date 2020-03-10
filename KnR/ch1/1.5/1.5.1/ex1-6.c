/* Verify that getchar() != EOF is 0 or 1 */

#include <stdio.h>

main ()
	{
		while (1) {
			int c;
			printf("%d", (getchar() != EOF) );	/* Send EOF by pressing ^D */
		}
	}
