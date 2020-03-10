/* There is no error checking in day_of_year or month_day. Remedy this defect. */

#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year(): set day of year from month and day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if ( year > 0 && month > 0 && month < 13 && day > 0 && day <= daytab[leap][month] ) {
    for (i = 1; i < month; ++i) {
      day += daytab[leap][i];
    }
    return day;
  }

  else return -1;
}

/* month_day(): set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (yearday == 0 || yearday > (365 + leap) || year == 0)
    return -1;

  for (i = 1; yearday > daytab[leap][i]; ++i)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
  return 0;
}

/* rudimentary storage allocator */

#define ALLOCSIZE 10000    /* size of available space */

static int allocbuf[ALLOCSIZE];    /* storage for alloc */
static int *allocp = allocbuf;     /* next free position */

int *alloc(int n)    /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n)   {   /* it fits */
    allocp += n;
    return allocp - n;  /* old p */
  } else    /* not enough room */
    return 0;
}

void afree(int *p)   /* free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

main()
{
  int days, month, year, *pmonth = alloc(sizeof(int)), *pday = alloc(sizeof(int)), yeardays;

  /* gtest day_of_year */
  scanf("%d %d %d", &days, &month, &year);
  if ((yeardays = day_of_year(year, month, days)) > 0)
    printf("For day %d of month %d of year %d, the day of year is: %d\n", days, month , year, yeardays);
  else printf("wrong input for day_of_year\n");


  /* test month_day */
  scanf("%d %d", &days, &year);
  if ( month_day(year, days, pmonth, pday) > 0)
    printf("Day %d of the year occurred on the day %d of the month %d\n", days, *pday, *pmonth);
  else printf("wrong input for month_day\n");
}
