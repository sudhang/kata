/* echo command-line arguments: 2st version */
#include <stdio.h>

main(int argc, char *argv[])
{
  int i = 0;

  while (--argc)  {
    printf("%s%s", *++argv, (argc > 1) ? " ":"");
  }
  printf("\n");

  return 0;
}
