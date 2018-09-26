// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
#include <stdio.h>
#define R 3
#define C 6

// 	row - Ending row index
// 	col - Ending column index
void printSpiral(int row, int col, int matrix[R][C])
{
	// Starting row index
	int r; 
	// Starting column index
	int c;
	
	while (r < row && c < col)
	{
		// Print top row
		for (int i = c; i < col; ++i)
		{
			printf("%d ", matrix[r][i]);
		}
		r++;

		// Print right column
		for (int i = r; i < row; ++i)
		{
			printf("%d ", matrix[i][col-1]);
		}
		col--;

		// Print bottom row
		// This check is need to handle matrix having odd number of rows
		// For matrix with odd number of rows skip printing same element two times
		if ( r < row)
		{
			for (int i = col-1; i >= c; --i)
			{
				printf("%d ", matrix[row-1][i]);
			}
			row--;
		}

		// Print left column
		// This check is need to handle matrix having odd number of columns
		// For matrix with odd number of columns skip printing same element two times
		if (c < col)
		{
			for (int i = row-1; i >= r; --i)
			{
				printf("%d ", matrix[i][c]);
			}
			c++; 
		}	 
	}
}

/* Driver program to test above functions */
int main()
{
	int a[R][C] = { {1, 2, 3, 4, 5, 6},
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18}
	};

	printSpiral(R, C, a);
	return 0;
}
