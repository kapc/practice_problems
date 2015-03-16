#include <stdio.h>
#include <stdlib.h>

#define MAX 6

/*
 *----------------------------------------------------------------------------
 * swapElem --
 *    Swap two values.
 *-----------------------------------------------------------------------------
 */

void swapElem(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

/*
 * ----------------------------------------------------------------------------
 * sortArray --
 *    Sort the array using insertion sort.
 *
 * Returns:
 *    Sorted array.
 * ----------------------------------------------------------------------------
 */

void sortArray(int *arr, int len)
{
   int i = 0, j = 0;
   for (i = 0; i < len; i++) {
      for(j = i; j < len; j++) {
         if (arr[j] < arr[i]) {
            swapElem(&arr[j], &arr[i]);
         }
      }
   }
}

/*
 * ----------------------------------------------------------------------------
 * printArray --
 *    Print the array.
 * ----------------------------------------------------------------------------
 */

void printArray(int *arr, int len)
{
   int i = 0;
   for (i = 0; i < len; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

/*
 * ----------------------------------------------------------------------------
 * findPrintPairSum --
 *    find and print the pair sum values.
 * ---------------------------------------------------------------------------
 */

void findPrintPairSum(int sum, int *arr, int len)
{
   int i = 0, j = len - 1;

   // Sort the array first.
   sortArray(arr, len);
   printArray(arr, len);

   // Keep two pointers, one pointed to at the start of the array and
   // other pointed to the end of the array. Iterate over the array
   // while incrementing i and decrementing j and check if the pair
   // sum is equal to the sum given.
   while (i < j) {
      if ((arr[i] + arr[j]) < sum) {
         i++;
      } else if((arr[i] + arr[j]) > sum) {
         j--;
      } else {
         printf("Value %d %d\n", arr[i++], arr[j--]);
      }
   }
}

int main() {
   int arr[MAX] = {1, 4, 0, -3, 8, 9};
   int sum = 0;

   // Test the sort Array method.
   // sortArray(arr, MAX);
   // printArray(arr, MAX);
   printf("Please enter the sum:\n");
   scanf("%d", &sum);

   findPrintPairSum(sum, arr, MAX);
}
