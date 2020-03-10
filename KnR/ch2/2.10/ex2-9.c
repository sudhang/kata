/* In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x
 * Explain why. Use this observation to write a faster version of bitcount.
 *
 * Explanation
 *
 * x - 1 = x + (-1)
 *
 * in binary, -1 = 1111 1111 1111 1111 1111 1111 1111 1111
 *
 * now, when we add this to x, starting from the LSB, as long as we encounter 0s
 * we will get 1 in the result. 
 *
 * When 1 is first encountered, 1 + 1 = 10 
 * thus, 0 will be put in the bit position and 1 will carry. This way, the bitstring
 * will be a series of 1s at the right, followed by a 0 at the position of the first 1.
 *
 * Now, if the next bit is 1, then 1 + 1 + 1 = 11
 * thus, 1 will be put in the bit position and 1 will carry. So, 1 in the bitstring is preserved.
 *
 * If the next bit is 0, then 1 + 1 = 11
 * thus 0 will be put in the bit position and 1 will carry. This way, the 0 in the bitstring is 
 * preserved.
 *
 * Thus, the string remains the same as before, except that 
 *  a) the bits before the first 1 are all turned to 1s
 *  b) the first 1 bit is set to 0
 *
 * Now, when we AND x to this result, we will have all 0s at first.. Then, the first 1 will also 
 * be 0. After that, the numbers will be same as before. The effect is that the first 1 is stripped out.
 */

#include <stdio.h> 

#define MAXLINE 15

int bitcount(unsigned x)
{
  int i;

  for (i = 0; x != 0; x /= ( (x ^ ( x & ( x - 1 ) ) ) * 2 ), ++i)
    printf("\nx: %d", x);

  return i;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

main()
{
  int len;
  unsigned num;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0) {
    num = atoi(line);

    printf("\nThe number of 1s in the binary form of %d is: %i\n", num, bitcount(num));
  }
}
