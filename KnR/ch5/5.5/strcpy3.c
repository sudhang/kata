/* strcpy: copy t to s; pointer version 1 */
#include <stdio.h>

void strcpy(char *s, char *t)
{
  int i = 0;

  while ((*s++ = *t++) != '\0')
    ;
}

main()
{
  char apple[100] = "hello this is apple", orange[100];

  strcpy(orange, apple);

  printf("%s\n", orange);
}
