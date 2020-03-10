#include <stdio.h>

int main(int argc, const char *argv[])
{
	char p[] = "%d\n";
	p[0] = 'c';
	printf(p,65);
	return 0;
}
