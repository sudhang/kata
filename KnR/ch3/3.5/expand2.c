#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void expand(char from[])
{
  int i;
  char c;

  for (i = 0; from[i] != '\0'; ++i )  {
    printf("%c",from[i]);

    if(from[i+1] == '-' && from[i+2] != '\0') {
        if (from [i] < from[i+2])
          for (c = from[i] + 1; c != from[i+2]; ++c)
            printf("%c",c);
        else if (from[i] > from[i+2]) {
          for (c = from[i] - 1; c != from[i+2]; --c)
            printf("%c",c);
        }
        ++i;      //Skip the -
    }
  }
  printf("\n");
}


main() {
  char *s[] = { "a-d", "z-a-", "-1-6-",
    "a-ee-a", "a-R-L", "1-9-1",
    "5-5", NULL };
  char result[100];
  int i = 0;

  while ( s[i] ) {

    //  Expand and print the next string in our array s[]  

    expand(s[i]);
    ++i;
  }

}
