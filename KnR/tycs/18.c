#include <stdio.h>

int main(int argc, const char *argv[])
{
	extern int i;
	i = 20;
	printf("%d\n",sizeof(i));
	return 0;
	return 0;
}
