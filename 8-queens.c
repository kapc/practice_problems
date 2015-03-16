#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4
// Main board layout.
static int board[MAX][MAX];

void printBoard(int [][MAX]);

/*
 * -----------------------------------------------------------------------
 * isSafe --
 *    Check if the queen position is safe or not.
 *
 * Returns:
 *    true if safe, false otherwise.
 */
bool isSafe(int board[][MAX], int row, int col)
{
   int i = 0, j = 0;
   // Check if any queen is already there is the same row.
   for(i = col; i >=0; i--) {
      if (board[row][i] == 1) {
         return false;
      }
   }
   // Check if lower diagonal is already taken.
   for(i = col, j = row; i >=0 && j < MAX; i--,j++) {
      if (board[i][j] == 1) {
         return false;
      }
   }
   // Check if higher diagonal is already taken.
   for(i = col, j = row; i >= 0 && j >=0; i--, j--) {
      if (board[i][j] == 1) {
         return false;
      }
   }

   return true;
}

/*
 * -----------------------------------------------------------------------
 * SolveMaxQueens --
 *    Recursively select rows in each column to put the queen.
 *
 * Returns:
 *    true if solved, false otherwise.
 *------------------------------------------------------------------------
 */
bool solveMaxQueens(int board[][MAX], int col)
{
   int i = 0;

   if (col > MAX) {
      // Found the solution
      return true;
   }

   for (i = 0; i < MAX; i++) {
      // Check if this position is safe.
      if(isSafe(board, i, col)) {
         // Mark this position.
         board[i][col] = 1;
         if(solveMaxQueens(board, col + 1)) {
            return true;
         }
         // Backtrack!!!.
         board[i][col] = 0;
      }
   }
   return false;
}

/*
 * -----------------------------------------------------------------------
 * printBoard --
 *    print board.
 * ----------------------------------------------------------------------
 */
void printBoard(int board[][MAX])
{
   int i = 0, j = 0;
   for (i = 0; i < MAX; i++) {
      for (j = 0; j <  MAX; j++) {
         printf("%d ", board[i][j]);
      }
      printf("\n");
   }

}

int main(void) {
   if (solveMaxQueens(board, 0)) {
      printBoard(board);
   }
   return 0;
}
