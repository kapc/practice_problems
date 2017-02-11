#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str, int left, int right) {
	char c = str[left];
	str[left] = str[right];
	str[right] = c;
}

void permute(char *str, int left, int right)
{
	if (left >= right) {
		printf("%s\n", str);
		return;
	}

	for (int i = left; i <= right; i++) {
		swap(str, left, i);
		permute(str, left + 1, right);
		swap(str, left, i);	
	}
}

int main(void)
{
	char str[] = "abc";
	permute(str, 0, strlen(str) - 1);
}
