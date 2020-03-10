#include<stdio.h>

main()
{
  char *s;
  int p1, p2;
  s = "The quick brown fox jumps over the lazy dog.\n";
  p1 = 10;
  p2 = 15;
  printf("%.*s \n%.*s \n", p1, s, p2, s);
}
