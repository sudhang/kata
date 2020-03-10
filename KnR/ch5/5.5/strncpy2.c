/* strcpy: copy t to s; pointer version 1 */
#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
  int i = 0;

  while ((*s = *t) != '\0' && i < n)   {
    s++;
    t++;
    i++;
  }

  *s-- = '\0';
}

main()
{
  char apple[100] = "hello this is apple", orange[100];

  strncpy(orange, apple, 7);

  printf("%s\n", orange);
}
