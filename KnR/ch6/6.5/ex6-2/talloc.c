#include "ex6-2.h"

/* talloc: make a tnode */
struct typenode *talloc(void)
{
  return (struct typenode *) malloc(sizeof(struct typenode));
}
