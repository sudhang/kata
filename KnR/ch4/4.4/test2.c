#include <stdio.h>

main ()
{
  extern void f1();
  f2();
}

void f1()
{
  printf("this is f1\n");
}

void f2()
{
  printf("this is f2\n");
  f1();
}
