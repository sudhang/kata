/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

#include <stdio.h>

int binsearch (int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while ( low <= high ) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else return mid;  /*match found*/
  }

  return -1;
}

int main(void)
{
  int test[]={1,3,5,7,9,11,13};
  int i;
  for(i=(sizeof(test)/sizeof(int))-1; i>=0; --i)
    printf("looking for %d. Index=%d\n",test[i],binsearch(test[i], test, sizeof(test)/sizeof(*test)));

  return 0;
}

