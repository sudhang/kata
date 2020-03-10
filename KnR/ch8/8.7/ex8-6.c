#include "syscalls2.h"
#include <unistd.h>
#include <limits.h>

static Header base;       /* empty list to get started */
static Header *freep = NULL;  /* start of free list */
static Header *morecore(unsigned);

/* Malloc: general-purpose storage allocator */
void *Malloc(unsigned nbytes)
{
  Header *p, *prevp;
  unsigned nunits;

  nunits = (nbytes+sizeof(Header)-1);

  nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {    /* no free list yet */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {      /* big enough */
      if (p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else  {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p + 1);
    }
    if (p == freep)       /* wrapped around free list */
      if ((p = morecore(nunits)) == NULL)
        return NULL;                      /* no units left */
  }
}

#define NALLOC 1024         /* minimum number of units to request */
/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
  char *cp, *sbrk(int);
  Header *up;

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *) -1)         /* no space at all */
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  free((void *)(up+1));
  return freep;
}

/* free: put block ap in free list */
void free(void *ap)
{
  Header *bp, *p;

  bp = (Header *)ap - 1;        /* point to block header */
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;            /* freed block at start or end of arena */

  if (bp + bp->s.size == p->s.ptr)  {       /* join to upper neighbor */
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;                   /* helps make CLL */
  if (p + p->s.size == bp) {                /* join to lower neighbor */
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

/* mycalloc: return a pointed to n objects of size 'size' */
void *mycalloc(int n, unsigned size)
{
  char *p, *q;
  int i;
  q = p = (char *) Malloc(n*size);

  for (i = 0; i < n*size ; i++)
    *p++ = 0;

  return (void *) q;
}

/* simple test driver, by RJH */

int main(void)
{
  int *p = NULL;
  int i = 0;

  p = mycalloc(10, sizeof *p);
  if(NULL == p)
  {
    printf("mycalloc returned NULL.\n");
  }
  else
  {
    for(i = 0; i < 10; i++)
    {
      printf("%08X ", p[i]);
      if(i % 8 == 7)
      {
	printf("\n");
      }
    }
    printf("\n");
    free(p);
  }

  return 0;
}
