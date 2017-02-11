#include <stdio.h>
#include <stdlib.h>

int DFS_helper(int **matrix, int idx, int jdx, int **visited, int n, int m) {
	int i = idx, j = jdx;
	if (i >= n || j >= m || i < 0 || j < 0) {
		return 0;
	}

	if (j+1 < m && matrix[i][j+1] == 1 && visited[i][j+1] == 0) {
		visited[i][j+1] = 1;
		return DFS_helper(matrix, i, j+1, visited, n, m) + 1;
	} else if (i+1 < n && j+1 < m && matrix[i+1][j+1] == 1 && visited[i+1][j+1] == 0) {
		visited[i+1][j+1] = 1;
		return DFS_helper(matrix, i+1, j+1, visited, n, m) + 1;
	} else if (i+1 < n && matrix[i+1][j] == 1 && visited[i+1][j] == 0) {
		visited[i+1][j] = 1;
		return DFS_helper(matrix, i+1, j, visited, n, m) + 1;
	} else if (i+1 < n && j-1 >=0 && matrix[i+1][j-1] == 1 && visited[i+1][j-1] == 0) {
		visited[i+1][j-1] = 1;
		return DFS_helper(matrix, i+1, j-1, visited, n, m) + 1;
	} else if (j - 1 >= 0 && matrix[i][j-1] == 1 && visited[i][j-1] == 0) {
		visited[i][j-1] = 1;
		return DFS_helper(matrix, i, j-1, visited, n, m) + 1;
	} else if (i - 1 >= 0 && matrix[i-1][j] == 1 && visited[i-1][j] == 0) {
		visited[i-1][j] = 1;
		return DFS_helper(matrix, i - 1, j, visited, n, m) + 1;
	} else if (i - 1 >= 0 && j - 1 >= 0 && matrix[i-1][j-1] == 1 && visited[i-1][j-1] == 0) {
		visited[i-1][j-1] = 1;
		return DFS_helper(matrix, i - 1, j - 1, visited, n, m) + 1;
	} else if (i - 1 >= 0 && j + 1 < m && matrix[i-1][j+1] == 1 && visited[i-1][j+1] == 0) {
		visited[i-1][j+1] = 1;
		return DFS_helper(matrix, i - 1, j + 1, visited, n, m) + 1;
	}

	return 0;
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

	printf("%d", count);
}

int main(){

    int n; 
    scanf("%d",&n);
    int m; 
    scanf("%d",&m);

    int *matrix[n], *visited[n];


	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(sizeof(int) * m);
		visited[i] = malloc(sizeof(int) * m);
	}
    
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          scanf("%d",&matrix[grid_i][grid_j]);
          visited[grid_i][grid_j] = 0;
       }
    }
    
 	printf("dfs");
    countMaxRegionSize(matrix, visited, n, m);
    return 0;
}
