/* echo command-line arguments: 2st version */
#include <stdio.h>

main(int argc, char *argv[])
{
  int i = 0;

  while (--argc)  {
    printf((argc > 1) ? "%s ":"%s", *++argv);
  }
  printf("\n");

  return 0;
}
