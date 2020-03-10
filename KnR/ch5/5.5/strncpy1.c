/* strcpy: copy t to s; array subscript version */
#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
  int i = 0;

  while ((s[i] = t[i]) != '\0' && i < n)
    i++;

  s[i] = '\0';
}

main()
{
  char apple[100] = "hello this is apple", orange[100];

  strncpy(orange, apple, 7);

  printf("%s\n", orange);
}
