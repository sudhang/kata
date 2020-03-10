/* Write an alternate version of squeeze(s1,s2) that deletes each 
 * character in s1 that matches any character in the string s2 */

#include <stdio.h>

#define MAXLINE 100
#define MATCHED 1

void squeeze(char s1[], char s2[])
{
  int i, j, k, state;

  for (i = j = 0; s1[i] != '\0'; ++i)  {
    state = (!MATCHED); 
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) {
        state = MATCHED;
        break;
        }
    }
    if (state != MATCHED) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
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
