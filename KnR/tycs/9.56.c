#include <stdio.h>

int main(int argc, const char *argv[])
{
	static char s[25] = "The cocaine man";
	int i = 0;
	char ch;
	ch = s[++i];
	printf("%c\n",ch);
	ch = s[i++];
	printf("%c\n",ch);
	ch = i++[s];
	printf("%c\n",ch);
	ch = ++i[s];
	printf("%c\n",ch);
	return 0;
}
