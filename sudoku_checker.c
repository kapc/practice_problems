#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 9

/*
 * ------------------------------------------------------------------------------------------------
 * Check3x3Grid --
 *       Checks 3x3 sudoku to be valid.
 *
 * Returns:
 *    True if valid, false otherwise.
 *-------------------------------------------------------------------------------------------------
 */
bool Check3X3Grid(int sudoku[][MAX_SIZE], int row, int column)
{
   int seen[MAX_SIZE] = {0};
   int i = 0, j = 0;

   for(i = row; i < row + 3; i++) {
      for(j = column; j < column + 3; j++) {
         if(seen[sudoku[i][j]]) {
            return false;
         }
         seen[sudoku[i][j]] = 1;
      }
   }

   return true;
}

/*
 * ------------------------------------------------------------------------------------------------
 * CheckSudoku --
 *    Checks the Sudoku checker.
 *
 * Returns:
 *    true if valid, false otherwise.
 * ------------------------------------------------------------------------------------------------
 */
bool CheckSudoku(int sudoku[][MAX_SIZE]) {
   int i = 0, j = 0;

   for(i = 0; i < MAX_SIZE; i += 3) {
      for (j = 0; j < MAX_SIZE; j +=3) {
         if(Check3X3Grid(sudoku, i, j) == false) {
            return false;
         }
      }
   }
   return true;
}

