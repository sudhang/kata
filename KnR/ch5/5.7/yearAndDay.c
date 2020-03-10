/* day_of_year() converts the month and day into the day of the year
 * month_day() converts the day of the year into the month and day.
 *
 * shows the use of multi-dimensional arrays
 */
#include <stdio.h>

#define MONTH 5
#define YEARDAYS 234
#define YEAR 1987

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year(): set day of year from month and day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; ++i) {
    day += daytab[leap][i];
  }
  return day;
}

/* month_day(): set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; ++i)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

main()
{
  int days, month, year, yeardays;

  /* gtest day_of_year */
  scanf("%d %d %d", &days, &month, &year);
  printf("For day %d of month %d of year %d, the day of year is: %d\n", days, month , year, day_of_year(year, month, days));


  /* test month_day */
  scanf("%d %d", &yeardays, &year);
  month_day(year, yeardays, &month, &days);
  printf("Day %d of the year occurred on the day %d of the month %d\n", yeardays, days, month);
}
