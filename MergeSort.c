// -----------------------------------------------------------
// -----------------------------------------------------------
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations.
void Merge(int *arr, int start, int mid, int end);
void MergeSort(int *arr, int len);
void MergeSortHelper(int *arr, int start, int end);

/*
 * --------------------------------------------------------
 *  MergeSort --
 *      Sort an array using merge.
 * --------------------------------------------------------
 */
void
MergeSort(int *arr, int len)
{
    MergeSortHelper(arr, 0, len - 1);
}

/*
 * --------------------------------------------------------
 *  MergeSortHelper --
 *      Merge sort helper routine.
 * --------------------------------------------------------
 */
void
MergeSortHelper(int *arr, int start, int end)
{
    int mid; 

    /* Make sure to return at single element array. */
    if (start >= end) {
        return;
    }

    /* Be careful for int overflow. */
    mid = start + (end - start) / 2;
    MergeSortHelper(arr, start, mid);
    MergeSortHelper(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

/*
 * --------------------------------------------------------
 * Merge --
 *
 *  This routine basically merges two given list in sorted 
 *  order.
 * -------------------------------------------------------
 */
void Merge(int *arr, int start, int mid, int end)
{
    int len = end - start + 1;
    int i = start, j = mid, k = mid + 1, l = end;
    int index = 0;
    int tmp[len];

    memset(tmp, 0, len);

    while(i <= j && k <= l) {
        if(arr[i] < arr[k]) {
            tmp[index++] = arr[i++];
        } else {
            tmp[index++] = arr[k++];
        }
    }

    while(k <= l) {
        tmp[index++] = arr[k++];
    }

    while(i <= j) {
        tmp[index++] = arr[i++];
    }

    for(i = start, index = 0; i <= end; i++) {
        arr[i] = tmp[index++];
    }
}

int 
main(void)
{
    int arr[10] = {1, 45, 23, 4, 5, 224, 5, 21, 66, 1};
    int i = 0;
    MergeSort(arr, 10);

    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}
