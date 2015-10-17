#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int 
QuickSort_Partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start, j = end;
    do {
        while (i < j && arr[i] <= pivot) {
            i++;    
        }
        while(i < j && arr[j] >= pivot) {
            j--;
        }
        swap(&arr[i], &arr[j]);
    } while(i < j);

    swap(&arr[j], &arr[end]);
    return i;
}

void 
QuickSort(int *arr, int start, int end)
{
    int partition;
    if (start >= end) {
        return;
    }
    partition = QuickSort_Partition(arr, start, end);
    QuickSort(arr, start, partition - 1);
    QuickSort(arr, partition + 1, end);
}

int main(void) {
    int  i = 0;
    int arr[18] = {12, 3, 34, 56, 44, 11, 0, 23, 232, 23, 13, 1, 13, 14514, 1};
    QuickSort(arr, 0, 17);
    for(i = 0; i < 18; i++) {
        printf("%d\n", arr[i]);
    }
}
