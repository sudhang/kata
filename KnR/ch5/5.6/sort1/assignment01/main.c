/* assignment 01: make a two-dimensional array of students' names 
 * and sort it, using only pointers
 */

#include <stdio.h>
#include <string.h>                   /* for strcmp() */
#define NSTUDENTS 5

/*swap: interchange v[i] and v[j] */
void swap(char **v, int i, int j)
{
  char *temp;

  temp = *(v + i);
  *(v + i) = *(v + j);
  *(v + j) = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char **v, int left, int right)
{
  int i, last;
  if (left >= right)    /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(*(v + i), *(v + left)) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

main()
{
  char *student[] = {
    "manit pawar",
    "sudhang shankar",
    "manu jindal",
    "li li hao",
    "abhishek kumar"
  };

  qsort(student, 0, NSTUDENTS);
  int n = 0;

  while ( n < NSTUDENTS ) {             /* loop to print names alphabetically */
    printf("%s \n", *(student + n));
    n++;
  }

}
