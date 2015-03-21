#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/*
 * ----------------------------------------------------------------------------
 *  isValid --
 *    Check if the string is a valid integer.
 * ----------------------------------------------------------------------------
 */
bool isValid(char *str)
{
   int len = strlen(str);
   int i = 0;

   for (i = len - 1; i >= 1; i--) {
      if ((str[i] < '0' || str[i] > '9') && (i != 0 && str[i] == '-')) {
         return false;
      }
   }
   return true;
}

/*
 * ----------------------------------------------------------------------------
 *  strToIntHelper --
 *    Helper method to calculate the number.
 *
 *  Returns:
 *    Return the number.
 * ----------------------------------------------------------------------------
 */
int strToIntHelper(char *str, int start, int end)
{
   int i = end, j = 0;
   int val = 0;

   for (; i >= start; i--, j++) {
      val += (str[i] - '0') * pow(10, j);
   }

   return val;
}

/*
 *-----------------------------------------------------------------------------
 * strToInt --
 *    Convert the string to interger. First verify the validity.
 *
 * Returns:
 *    Return the resulting integer.
 * ----------------------------------------------------------------------------
 */

bool strToInt(char *str, int *result)
{
   if (isValid(str)) {
      char *tmp = str;
      int len = strlen(tmp);
      int val = 0, i, j;

      if (str[0] == '-') {
         val = -1 * strToIntHelper(str, 1, len - 1);
      } else {
         val = strToIntHelper(str, 0, len - 1);
      }

      *result = val;
      return true;
   }

   *result = -1;
   return false;
}

/*
 *-----------------------------------------------------------------------------
 * TestProgram --
 *    Test all the usecases.
 *-----------------------------------------------------------------------------
 */
void TestProgram(void)
{
   int result;
   bool res;

   res = strToInt("123", &result);
   assert(res && result == 123);

   res = strToInt("-123",  &result);
   assert(res && result == -123);

   res = strToInt("-1-2-3-", &result);
   assert(!res);
}

int main(void) {
   int resultInt = 0;
   bool res = false;

   TestProgram();
}
