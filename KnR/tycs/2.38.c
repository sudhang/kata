#include <stdio.h>

int main(int argc, const char *argv[])
{
	int n = 0, y = 1;
	(y == 1) ? (n = 0) : (n = 1);
	if (n) {
		printf("yes\n");	
	}
	else	printf("no\n");
	return 0;
}
