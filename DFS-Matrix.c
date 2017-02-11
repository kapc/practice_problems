#include <stdio.h>
#include <stdlib.h>

int DFS_helper(int **matrix, int idx, int jdx, int **visited, int n, int m) {
	int i = idx, j = jdx, count = 1;
	if (i >= n || j >= m || i < 0 || j < 0) {
		return 0;
	}

	if (j+1 < m && matrix[i][j+1] == 1 && visited[i][j+1] == 0) {
		visited[i][j+1] = 1;
		count = DFS_helper(matrix, i, j+1, visited, n, m) + 1;
		printf("%d %d\n", i, j+1);
	} else if (i+1 < n && j+1 < m && matrix[i+1][j+1] == 1 && visited[i+1][j+1] == 0) {
		visited[i+1][j+1] = 1;
		count = DFS_helper(matrix, i+1, j+1, visited, n, m) + 1;
		printf("%d %d\n", i+1, j+1);
	} else if (i+1 < n && matrix[i+1][j] == 1 && visited[i+1][j] == 0) {
		visited[i+1][j] = 1;
		count = DFS_helper(matrix, i+1, j, visited, n, m) + 1;
		printf("%d %d\n", i+1, j);
	} else if (i+1 < n && j-1 >=0 && matrix[i+1][j-1] == 1 && visited[i+1][j-1] == 0) {
		visited[i+1][j-1] = 1;
		count = DFS_helper(matrix, i+1, j-1, visited, n, m) + 1;
		printf("%d %d\n", i+1, j-1);
	} else if (j - 1 >= 0 && matrix[i][j-1] == 1 && visited[i][j-1] == 0) {
		visited[i][j-1] = 1;
		count = DFS_helper(matrix, i, j-1, visited, n, m) + 1;
		printf("%d %d\n", i, j-1);
	} else if (i - 1 >= 0 && matrix[i-1][j] == 1 && visited[i-1][j] == 0) {
		visited[i-1][j] = 1;
		count = DFS_helper(matrix, i - 1, j, visited, n, m) + 1;
		printf("%d %d\n", i-1, j);
	} else if (i - 1 >= 0 && j - 1 >= 0 && matrix[i-1][j-1] == 1 && visited[i-1][j-1] == 0) {
		visited[i-1][j-1] = 1;
		count = DFS_helper(matrix, i - 1, j - 1, visited, n, m) + 1;
		printf("%d %d\n", i-1, j-1);
	} else if (i - 1 >= 0 && j + 1 < m && matrix[i-1][j+1] == 1 && visited[i-1][j+1] == 0) {
		visited[i-1][j+1] = 1;
		count = DFS_helper(matrix, i - 1, j + 1, visited, n, m) + 1;
		printf("%d %d\n", i-1, j+1);
	}

	printf("%d\n", count);
	return count;
}

void ClearVisited(int **visited, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void countMaxRegionSize(int** matrix, int **visited, int n, int m) {
	int i = 0, j = 0;
	int count = 0, curCount = 0;
	for (i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if (matrix[i][j] == 1 && visited[i][j] == 0) {
				curCount = DFS_helper(matrix, i, j, visited, n, m);
				if (curCount > count) {
					count = curCount;
				}
			}
		}
	}

	printf("max %d", count);
}

int main(void) {

	int **matrix, **visited;
	int n = 4, m = 4;

	matrix = malloc(sizeof(int) * n);
	visited = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(sizeof(int) * m);
		visited[i] = malloc(sizeof(int) * m);
	}

	/*
	int matrix[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 1, 0, 0}
	}; */

	countMaxRegionSize(matrix, visited, 4, 4);
}
