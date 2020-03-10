/* Write an alternate version of squeeze(s1,s2) that deletes each 
 * character in s1 that matches any character in the string s2 */

#include <stdio.h>

#define MAXLINE 100
#define MATCHED 0


void squeeze1(char s[], char c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c)
      s[j++] = s[i];
  }

  s[j] = '\0';
}

void squeeze(char s1[], char s2[])
{
  int i;

  for (i = 0; s2[i] != '\0' ; ++i)
    squeeze1(s1,s2[i]);
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
    squeeze(string1, string2);
    printf("The new string is: %s\n", string1);
  }
}
