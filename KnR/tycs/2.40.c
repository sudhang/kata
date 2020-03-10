#include <stdio.h>

int main(int argc, const char *argv[])
{
	static int svar = 0;
	printf("call number: %d\n", svar++);
	main(argc,argv);
	return 0;
}
