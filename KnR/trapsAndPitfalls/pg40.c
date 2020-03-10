#include <stdio.h>

int main(int argc, const char *argv[])
{
	int A[6] = { 1, 2, 3, 4, 5, 6, }, *pInt;

	pInt = A;
	while (pInt < &A[6]) {
		printf("%p\t", pInt);
		printf("%d\n", *pInt++);
	}
	printf("%p\t%d\n", &A[6], A[6]);
	return 0;
}
