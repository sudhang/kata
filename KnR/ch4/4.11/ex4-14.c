/* Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block structure will help)
 */
#include <stdio.h>

#define swap(t, x, y) { t temp; temp = x; x = y; y = temp; }
#define AVAL 9564
#define BVAL 1234

main()
{
  int a = AVAL, b = BVAL;

  printf("A = %d B = %d\n", a, b);
  swap(int, a, b);
  printf("A = %d B = %d\n", a, b);
}
