#include <stdio.h>

/*
 * ----------------------------------------------------------------------------
 *  computeParity --
 *    Compute the parity of the number.
 * ----------------------------------------------------------------------------
 */
int computeParity(int num)
{
   int i = num, res = 0;

   while(i) {
      if (i & 1 == 1) {
         res = res ^ 1;
      } else {
         res = res ^ 0;
      }
      i = i >> 1;
   }
   return res;
}

int main(void)
{
   int num;
   scanf("%d", &num);
   printf("Parity is %d\n", computeParity(num));
}
