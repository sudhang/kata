/* Are arrays and pointers the same? */

#include <stdio.h>

#define SIZE 10

main ()
{
  int array[SIZE] = {34,65,98,54,765,45,46,456,234,89}, i, *parray;

  /* normal array indexing */
  printf("normal array indexing\n");
  for (i = 0; i < SIZE; ++i)
    printf("array[%d]: %d\n", i, array[i]);
  
  /* using pointers with indices */
  printf("using pointers with indices \n");
  for (i = 0; i < SIZE ; ++i)
    printf("array[%d]: %d\n", i, *(array + i));

  /* using pointers alone */
  printf("using pointers alone \n");
  for (parray = array; (parray - array) < SIZE ; ++parray)
    printf("array[%d]: %d\n", (parray - array), *parray);

  /* reversed indexing */
  printf("reversed indexing \n");
  for (i = 0; i < SIZE; ++i)
    printf("array[%d]: %d\n", i, i[array]);

  /* see what the array addresses are */
  printf("see what the array addresses are \n");
  for (parray = array; (parray - array) < SIZE ; ++parray)
    printf("array[%d] is at %u\n", (parray - array), parray);

}
