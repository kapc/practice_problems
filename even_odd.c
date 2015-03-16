#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

void reset_even_odd(int *arr, int len) {
   int i = 0, j = len - 1;

   while(i <= j) {
      while ((arr[i] & 1) == 0 && i < j) {
         i++;
      }
      while ((arr[j] & 1) == 1 && i < j) {
         j--;
      }
      if (i < j) {
         swap(&arr[i++], &arr[j--]);
      }
   }
}

void print_array(int *arr, int len) {
   int i = 0;
   for (i = 0; i < len; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}


int main() {
   int arr[11] = {1, 2, 3, 4, 11, 34, 53, 42, 22, 425, 233};
   reset_even_odd(arr, 11);
   print_array(arr, 11);
}
