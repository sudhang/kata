/* Shellsort */

#include <stdio.h>

void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)  {
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0 && v[j]>v[j+gap]; j-=gap)  {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
  }
}

void checkThatArrayIsSorted (int array[], int length)
{
  int i;
  for (i = 1; i < length; i+=1)
  {
    if (array[i-1] > array[i])
    {
      printf("The array is not in sorted order at position %d\n", i-1);
    }
  } 
}


int main(void)
{
  unsigned int i;
  int a[] = {5,1,9,3,2,4,76,4,78,2,5,78,33,4,76,23,13,568,4,43,563,2,5,54,78,23,85,5356,2,23,56,13,5,4,7,3,45,3,57,87,9,3,756,34,34,6,645,645,6,8,45,64,6,5634,646,4};
  shellsort(a, sizeof(a)/sizeof(*a));
  /* Print out a */
  for(i=0; i<sizeof(a)/sizeof(*a); i++)
  {
    printf("%d\n", a[i]);
  }

  checkThatArrayIsSorted(a, sizeof(a)/sizeof(*a));

  return 0;
}
