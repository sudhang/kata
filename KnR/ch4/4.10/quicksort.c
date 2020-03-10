/* qsort: sort v[left]...v[right] into increasing order */
#include <stdio.h>

#define ARRAY {123, 35, -234, 65, 934, 23, 9, 2345, 1234, 934}
#define ARRLENGTH 10

void swap(int v[], int i, int j);

void qsort(int v[], int left, int right)
{
  int i, last;
  
  if (left >= right)            /* do nothing if array contains fewer than two elements */
    return;

  swap(v, left, (left + right)/2);  /* move partition element */
  last = left;                      /* to v[0] */
  for (i = left + 1; i <= right; i++) /* partition */
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);              /* restore partition element */
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

main ()
{
  int array[] = ARRAY;
  int i;

  printf("unsorted: \n");
  for(i = 0; i < ARRLENGTH; ++i)
    printf("%d\t",array[i]);
  putchar('\n');

  qsort(array, 0, ARRLENGTH - 1);

  printf("sorted: \n");
  for(i = 0; i < ARRLENGTH; ++i)
    printf("%d\t",array[i]);
  putchar('\n');
}
