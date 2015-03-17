#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);
void listPrimeNumbersRange(int);

/*
 * ----------------------------------------------------------------------------
 * listPrimeNumbersRange --
 *    List all the prime numbers given the range.
 * ----------------------------------------------------------------------------
 */
void listPrimeNumbersRange(int range)
{
   int i = 0;

   for (i = 2; i < range; i++) {
      if(isPrime(i)) {
         printf("%d\n", i);
      }
   }
}

/*
 * ----------------------------------------------------------------------------
 * isPrime --
 *    Check if the number is prime.
 * ----------------------------------------------------------------------------
 */
bool isPrime(int num)
{
   int i = 2;

   while(i * i <= num) {
      if (num % i == 0) {
         return false;
      }
      i++;
   }
   return true;
}

int main(void) {
   int num = 0;
   scanf("%d", &num);
   listPrimeNumbersRange(num);
}
