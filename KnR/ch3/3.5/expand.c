/* Write a function expand(s1, s2) that expands shorthand notations like a-z
 * in the string s1 into equivalent complete list abc..xyz  in s2. Allow for 
 * letters of either case and digits, and be prepares to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void expand(char from[], char to[])
{
  int i, j = 0;
  char c;
  for (i = 0; from[i] != '\0'; ++i) {
      to[j++] = from[i];

    if ((from[i+1] == '-') && (from[i+2] != '\0') )  {
      if (from[i] < from[i+2])        //Case 1: the range is ascending
        for (c = from[i] + 1; c != from[i+2]; ++c)
          to[j++] = c;
      else if (from[i] > from[i+2])   //Case 2: the range is descending
        for (c = from[i] - 1; c != from[i+2]; --c)
          to[j++] = c;
      else  ++i;                         //Case 3: the range is redundant (i.e., it's of the form a-a)
    ++i;    //Skip the '-' in the next iteration
    }
  }
  to[j] = '\0';
}

main() {
  char *s[] = { "a-d-", "z-a-", "-1-6-",
    "a-ee-a", "a-R-L", "1-9-1",
    "5-5", NULL };
  char result[100];
  int i = 0;

  while ( s[i] ) {

    //  Expand and print the next string in our array s[]  

    expand(s[i], result);
    printf("Unexpanded: %s\n", s[i]);
    printf("Expanded  : %s\n", result);
    ++i;
  }

}

//main()
//{
//  int len;
//  char line[MAXLINE], expanded[MAXLINE];
//
//  while ( (len = getline(line, MAXLINE)) > 0 )  {
//    expand(line, expanded);
//    printf("Unexpanded: %s\n", line);
//    printf("Expanded  : %s\n", expanded);
//  }
//}
