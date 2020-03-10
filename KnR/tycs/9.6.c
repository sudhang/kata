#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a[] = "\0";
	int i;
	if (i = printf("%s",a)) {
		printf("the string is not empty\n");
	}
	else
		printf("the string is empty\n");
	printf(" %d\n", i);
	return 0;
}
