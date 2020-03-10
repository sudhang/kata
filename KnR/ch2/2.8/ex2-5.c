/* Write the function any(s1,s2) , which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no characters
 * from s2 . (The standard library function strpbrk does the same job but returns a pointer
 * to the location.)
 */

#include <stdio.h>

#define MAXLINE 100
#define MATCHED 1

int any(char s1[], char s2[])
{
  int i, k;

  for (i = 0; s1[i] != '\0'; ++i)  {
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) 
        return i;
    }
  }

  return -1;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

main()
{
  int len;
  char string1[MAXLINE], string2[MAXLINE];

  while ( (len = getline(string1, MAXLINE)) > 0 ) {
    printf("\nEnter the other string: ");
    getline(string2, MAXLINE);
    printf("A character was found at: %d\n", any(string1, string2));
  }
}
