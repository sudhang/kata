#include <stdio.h>
main ()
{
  struct s  {
  };
  printf("size of an empty struct: %d\n", sizeof(struct s));

  struct s array[10];
  printf("size of array of empty structs is: %d\n", sizeof(array));

  struct s *psd;
  psd = &array[0];
  printf("address of element 0 is: %u\n", psd);
  psd++;
  printf("address of element 1 is: %u\n", psd);
  printf("difference b/w addresses of elements is %d\n",((psd - array)*sizeof(struct s)));
}
