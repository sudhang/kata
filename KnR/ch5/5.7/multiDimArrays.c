/* day_of_year() converts the month and day into the day of the year
 * month_day() converts the day of the year into the month and day.
 *
 * shows the use of multi-dimensional arrays
 */
#include <stdio.h>

static int twoD[2][5] = {
  {34, 14, 76, 30, 66},
  {87, 20, 54, 96, 78}
};

static int threeD[3][2][2] = {
  { {34, 453}, {76, 873} },
  { {24, 65}, {54, 87} },
  { {12, 456}, {908, 92} }
};

main()
{
  printf("int  twoD[1][2] = %d\n", twoD[1][2]);
  printf("int  twoD[1][2] = %d\n", *(*(twoD + 1) + 2) );

  printf("int  threeD[1][2][1] = %d\n", threeD[2][1][1]);
  printf("int  threeD[1][2][1] = %d\n", *(*(*(threeD + 2) + 1) + 1) );
}
