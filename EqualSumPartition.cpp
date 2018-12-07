#include <stdio.h>

// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
bool EqualSumPartition (int arr[], int n)
{
  int arrSum = 0;
  int i, j;

  // Sum of all elements
  for (i = 0; i < n; i++) {
    arrSum += arr[i];
  }

  if (arrSum%2 != 0) {
    return false;
  }

  bool partSum[arrSum/2+1][n+1];

  // Initialize top row. Its set to 'true' because zero sum
  // can be found by taking no element from the array
  for (i = 0; i <= n; i++) {
    partSum[0][i] = true;
  }

  // Initialize leftmost column, set to 'false' as non  zero cannot
  // be obtained by selecting zero element from the array
  for (i = 1; i <= arrSum/2; i++) {
    partSum[i][0] = false;
  }

  // Fill the partition table
  for (i = 1; i <= arrSum/2; i++)
  {
    for (j = 1; j <= n; j++)
    {
      partSum[i][j] = partSum[i][j-1];

      if (i >= arr[j-1]){
        partSum[i][j] = partSum[i][j] || partSum[i - arr[j-1]][j-1];
      }
    }
  }

  return partSum[arrSum/2][n];
}

// Driver program to test above funtion
int main()
{
  int arr[] = {3, 1, 1, 2, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  if (EqualSumPartition(arr, n) == true)
    printf("Can be divided into two subsets of equal sum");
  else
    printf("Can not be divided into two subsets of equal sum");

  return 0;
}
