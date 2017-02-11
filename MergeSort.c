#include <stdio.h>

#define MAX 10

void Merge(int *a, int start, int end, int start1, int end1)
{
	int tmp[MAX], idx = 0;
	int i = start, j = end, k = start1, l = end1;
	printf("Merging %d %d %d %d\n", start, end, start1, end1);
	while(i <= j && k <= l) {
		if (a[i] < a[k]) {
			tmp[idx++] = a[i++];
		} else {
			tmp[idx++] = a[k++];
		}
	}

	while(i <= j) {
		tmp[idx++] = a[i++];
	}

	while(k <= l) {
		tmp[idx++] = a[k++];
	}

	for (i = 0, j = start; i < idx; i++, j++) {
		a[j] = tmp[i];
	}
}

void MergeSort(int *a, int start, int end)
{
	int mid;

	if (start >= end) {
		return;
	}

	mid = (start + end) / 2;
	MergeSort(a, start, mid);
	MergeSort(a, mid + 1, end);
	Merge(a, start, mid, mid + 1, end);
}

int main(void) 
{
	int a[MAX] = {1, 34, 3, 56, 99, 78, 43, 66, 22, 88};
	MergeSort(a, 0, 9);

	for (int i = 0; i < MAX; i++) {
		printf("%d ", a[i]);
	}
}
