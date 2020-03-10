/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
#include <stdio.h>

int strcmp(char *s, char *t)
{
  int i;

  for ( i = 0; s[i] == t[i]; i++ )
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

main()
{
  char array1[10] = "rofl", array2[10] = "rolf";

  printf("comparison b/w array1 %s and array2 %s: %d\n", array1, array2, strcmp(array1, array2));

}

