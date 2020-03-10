#include <stdio.h>

/* month_name: return name of the n-th month */
char *month_name(int n)
{
  static char *name[] = {
    "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };

  return (n > 0 && n < 13) ? name[n] : name[0];
}

main()
{
  int num;

  while (scanf("%d", &num) == 1)   {
    printf("Month number %d is %s\n", num, month_name(num));
  }
}
