/* strlen: return length of a string */

#include <stdio.h>

int strlen(char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    ++n;

  return n;
}

main ()
{
  char array1[23] = "helloworld!";
  char array2[23] = "asdfksdjfksdja!";
  char *ptr = &array2[3];

  printf("i like cake: len = %d\n", strlen("i like cake"));
  printf("%s: len = %d\n", array1, strlen(array1));
  printf("%s: len = %d\n", ptr, strlen(ptr));

}

