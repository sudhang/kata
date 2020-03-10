#include <stdio.h>

#define MAXLINE 100
#define NUM 34325235

/* printd: print n in decimal */
void printd(int n)
{
  if (n < 0)  {
    putchar('-');
    n = -n;
  }

  if (n / 10)
    printd(n / 10);

  putchar(n % 10 + '0');
}

main ()
{
  int num = NUM;

  printd(num);
  putchar('\n');
}
