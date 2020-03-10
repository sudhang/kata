/* structures for use in graphics */

#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define XMAX 300
#define YMAX 400

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

double area(struct rect r)      /* this function accepts a struct */
{
  return ( (double)(r.pt2.x - r.pt1.x) * (double)(r.pt2.y - r.pt1.y) );
}

struct point makepoint(int x, int y)      /* this function returns a struct */
{
  struct point temp;
  temp.x = x;
  temp.y = y;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{                                                         /* note that, although we are INCREMENTING p1.x, the ACTUAL */
  p1.x += p2.x;                                           /* p1.x is unaffected, since p1.x is passed by value, just  */
  p1.y += p2.y;                                           /* like any other variable                                  */
  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

main()
{
  struct point pt = { 0, 34 };
  double dist, sqrt(double);
  
  printf("%d,%d\n",pt.x,pt.y);
  dist = sqrt( (double)(pt.x * pt.x) + (double)(pt.y * pt.y) );
  printf("distance of these points from the origin is %lf\n", dist);

  struct rect rect1 = { { 10, 20 }, { 90, 80 } };
  printf("area of rectangle = %lf\n", area(rect1) );

  struct rect screen;
  struct point middle;
  
  screen.pt1 = makepoint(0, 0);
  screen.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint( (screen.pt1.x + screen.pt2.x)/2, (screen.pt1.x + screen.pt2.x)/2 );

  struct point origin = { 0, 0 }, *pp;
  pp = &origin;
  printf("origin is (%d, %d) \n", (*pp).x, (*pp).y);
  printf("origin is (%d, %d) \n", pp->x, pp->y);
}
