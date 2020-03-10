/* strcpy: copy t to s; array subscript version */
#include <stdio.h>

void strcpy(char *s, char *t)
{
  int i = 0;

  while ((s[i] = t[i]) != '\0')
    i++;
}

main()
{
  char apple[100] = "hello this is apple", orange[100];

  strcpy(orange, apple);

  printf("%s\n", orange);
}
