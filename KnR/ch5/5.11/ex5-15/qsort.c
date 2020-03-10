#include "sort.h"

/*swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(const char *p1, const char *p2)
{
  const char *s = reverse ? p2 : p1;
  const char *t = reverse ? p1 : p2;
  int gap = fold ? abs('A' - 'a') : 0;

  for ( ;abs(*s - *t) == gap ; s++, t++ )
    if (*s == '\0')
      return 0;
  return *s - *t;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *p1, const char *p2)
{
  const char *s1 = reverse ? p2 : p1;
  const char *s2 = reverse ? p1 : p2;

  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else 
    return 0;
}


/* qsort: sort v[left]...v[right] into increasing order */
void qsort1(void *v[], int left, int right, int(*comp)(const void *, const void *))
{
  int i, last;
  if (left >= right)    /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort1(v, left, last - 1, comp);
  qsort1(v, last + 1, right, comp);
}
