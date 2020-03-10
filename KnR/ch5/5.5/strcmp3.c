/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
#include <stdio.h>

int strcmp(char *s, char *t)
{
  for ( ; *s == *t ; s++, t++ )
    if (*s == '\0')
      return 0;
  return *s - *t;
}

main()
{
  char array1[10] = "rolf", array2[10] = "rofl";

  printf("comparison b/w array1 %s and array2 %s: %d\n", array1, array2, strcmp(array1, array2));

}

