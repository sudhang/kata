#include <stdio.h>

main()
{
  int i;
  float A[] = { 16.0, 2.0, 77.0, 40, 12071 };
  float B[] = { 1, 2, 77, 40, 22 };
  float C[5];

  C[1]=44;
  for(i=0;i<5;i++){
    printf("threadidx is %d,  A is %f , B is %f C is %f \n",i, A[i],B[i],C[i])   ; 
  }
}
