/* Write a pointer version of the function strcat that we showed in chapter 2.
 * strcat(s, t) copies the string t to the end of s
 */
#include <stdio.h>

void strcat(char *s, char *t)
{
  while ( *++s )
    ;

  while ( *s++ = *t++ )
    ;
}

main ()
{
  char array1[20] = "hello ", array2[10] = "world!";

  strcat(array1, array2);

  printf("array: %s\n", array1);

}
