#include <stdio.h>
#include <stdlib.h>

/*
 * ----------------------------------------------------------------------------
 * bitSwapping --
 *    swap two bits at given position in a number.
 *
 * Returns:
 *    Returns the new number
 * ----------------------------------------------------------------------------
 */
int bitSwapping(int num, int i, int j)
{
   int tmp = 0;
   if ((num >> i) & 1 != 0 && (num >> j) & 1 != 0) {
      tmp = (1L << i) | (1L << j);
      return tmp ^ num;
   }
   return num;
}

int main(void) {
   int num = 64;
   int i = 0, j = 2;

   printf("Origin num %d pos1 %d pos2 %d New %d\n", num, i, j, bitSwapping(num, i, j));
}
