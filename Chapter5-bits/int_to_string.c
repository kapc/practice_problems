#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *, char*);
void IntToString(int, char*);
void ReverseAString(char*);


#define MAX 10

/*
 * ----------------------------------------------------------------------------
 * Swap --
 *    Swap two pointers.
 * ----------------------------------------------------------------------------
 */

void Swap(char *p, char *q)
{
   char t = *p;
   *p = *q;
   *q = t;
}
/*
 * ----------------------------------------------------------------------------
 * IntToString --
 *    Convert an integer to a string.
 *
 * Returns:
 *    Return a string.
 * ----------------------------------------------------------------------------
 */
void IntToString(int num, char* result)
{
   int tmp = num, i = 0, mod = 0;
   int negative = 0;

   if (num < 0) {
      negative = 1;
      num = -num;
   }

   while(num != 0) {
      char c;
      mod = num % 10;
      c = '0' + mod;
      result[i++] = c;
      num = num / 10;
   }

   if(negative) {
      result[i++] = '-';
   }

   result[i] = '\0';
   ReverseAString(result);
}

/*
 * ----------------------------------------------------------------------------
 * ReverseAString --
 *    Reverse a string in-place.
 *-----------------------------------------------------------------------------
 */
void ReverseAString(char *res)
{
   int length = strlen(res);
   int i = 0, j = length - 1;

   while(i < j) {
      Swap(&res[i++], &res[j--]);
   }
}


/*
 * ----------------------------------------------------------------------------
 * TestProgram --
 *    Test the method.
 * ----------------------------------------------------------------------------
 */
void TestProgram(void)
{

}

int main(void)
{
   int num = -1;
   char result[MAX];

   IntToString(num, result);
   printf("%s", result);

}
