/* write versions of the library functions strncpy, strncat and strncmp which operated on at most the first
 * n chatacters of their argument strings. For example, strncpy(s, t, n) copies at most n chatacters of t to
 * s.
 */
#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
  int i = 0;

  while ( ( *s++ = *t++ ) != '\0' && ++i < n )
    ;

  if (*s != '\0')
    *s = '\0';
}

int strncmp(char *s, char *t, int n)
{
  int i;

  for (i = 0; ( *s == *t ) && i < n ; i++, s++, t++ )   {
    if (*s == '\0')
      return 0;
  }

  return *s - *t;
}

void strncat(char *s, char *t, int n)
{
  int i = 0;
  while ( *++s )
    ;

  while ( i++ < n && ( *s++ = *t++ ) != '\0' )
    ;

  if ( *s != '\0' )
    *s++ = '\0';
}

main()
{
  char apple[100] = "hello this is apple", orange[100];

  strncpy(orange, apple, 1);
  printf("%s\n", orange);
  strncpy(orange, apple, 2);
  printf("%s\n", orange);
  strncpy(orange, apple, 3);
  printf("%s\n", orange);
  strncpy(orange, apple, 4);
  printf("%s\n", orange);
  strncpy(orange, apple, 5);
  printf("%s\n", orange);
  strncpy(orange, apple, 6);
  printf("%s\n", orange);
  strncpy(orange, apple, 7);
  printf("%s\n", orange);
  strncpy(orange, apple, 8);
  printf("%s\n", orange);
  strncpy(orange, apple, 9);
  printf("%s\n", orange);
  strncpy(orange, apple, 10);
  printf("%s\n", orange);
  strncpy(orange, apple, 11);
  printf("%s\n", orange);
  strncpy(orange, apple, 12);
  printf("%s\n", orange);
  strncpy(orange, apple, 13);
  printf("%s\n", orange);
  strncpy(orange, apple, 14);
  printf("%s\n", orange);
  strncpy(orange, apple, 15);
  printf("%s\n", orange);
  strncpy(orange, apple, 16);
  printf("%s\n", orange);
  strncpy(orange, apple, 17);
  printf("%s\n", orange);
  strncpy(orange, apple, 18);
  printf("%s\n", orange);
  strncpy(orange, apple, 19);
  printf("%s\n", orange);
  char array1[15] = "caterpillar", array2[15] = "catabolism";

  printf("comparison b/w array1 %s and array2 %s: %d\n", array1, array2, strncmp(array1, array2, 6));

  strncat(array1, array2, 3);

  printf("array1: %s\n", array1);
}

