/* Write the function strend(s, t) which returns 1 if the string t occurs at the end of the string
 * s, and zero otherwise
 */
#include <stdio.h>

int strlen(char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    ++n;

  return n;
}

int strcmp(char *s, char *t)
{
  for ( ; *s == *t ; s++, t++ )
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int strend(char *s, char *t)
{
  int l = strlen(s) - strlen(t);
  
  return ( strcmp(s+l, t) == 0 );
}

main ()
{
  char array1[15] = "hello world", array2[15] = "orld", array3[15] = "ould";

  printf("array 1: %s array 2: %s isit: %d\n", array1, array2, strend(array1, array2));
  printf("array 1: %s array 2: %s isit: %d\n", array1, array3, strend(array1, array3));

}
