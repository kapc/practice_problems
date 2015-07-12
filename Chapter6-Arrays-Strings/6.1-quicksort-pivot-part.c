#include <stdio.h>

/*
 * ----------------------------------------------------------
 *  Swap --
 *   Simple swap of integers.
 * ----------------------------------------------------------
 */
void Swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * ----------------------------------------------------------
 *  DivideArrayWithPivot --
 *      This is basically part of quick sort but you sort the
 *      array in first and second half based on given value.
 *
 *  Examples:
 *  34, 4, 56, 2, 90, 33, 99, 23, 10 Pivot 33
 *  10, 4, 56, 2, 90, 33, 99, 23, 33
 *  10, 4, 23, 2, 90, 33, 99, 56, 33
 * ----------------------------------------------------------
 */
void DivideArrayWithPivot(int *arr, int len, int pivotIndex)
{
    int start = 0, end = len - 1;
    int pivot = arr[pivotIndex];
    while (start < end) {
 
        if (arr[start] > pivot && 
            arr[end] < pivot) {
            Swap(&arr[start], &arr[end]);
        }
        if (arr[start] < pivot) {
            start++;
        }
        if (arr[end] > pivot) {
            end--;
        }
    }
}

int main(void)
{
    int i = 0;
    int arr[10] = {34, 4, 56, 2, 90, 33, 99, 23, 10, 13};
    DivideArrayWithPivot(arr, 10, 5);

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}
