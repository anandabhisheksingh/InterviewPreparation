#define N 4
#include<stdio.h>
#include<stdbool.h>

int board[N][N] = {{0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};


void printBoard()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      printf(" %d ", board[i][j]);
    printf("\n");
  }
}

// Check if a queen can be placed on board[row][col].
// Queens are placed on the clumn in increasing order
bool isSafe(int row, int col)
{
  int i, j;

  // Check row on left side on 'col', as right side is not discovered yet
  for (i = 0; i < col; i++)
      if (board[row][i])
          return false;

  // Check upper left diagonal
  for (i= row, j = col; i>=0 && j>=0; i--, j--)
      if (board[i][j])
          return false;

  // Check lower left diagonal
  for (i=row, j=col; j >=0 && i < N; i++, j--)
      if (board[i][j])
          return false;

  return true;
}

// Place queen by filling columns in the board
// Valid solution requires that no two queens threaten each other.
// Thus, a solution requires that no two queens share the same row, column, or diagonal.
bool solveNQueens(int col)
{
  if (col >= N)
      return true;

  // Try to place queen in all possible rows for column 'col'
  for (int i = 0; i < N; i++){
      if (isSafe(i,col)){
        board[i][col] = 1;

        if (solveNQueens(col+1)){
          return true;
        }

        board[i][col] = 0;
    }
  }

  return false;
}

int main()
{
  if (solveNQueens(0) == false )
  {
    printf("Solution does not exist");
    return false;
  }

  printBoard();
  return 0;
}
