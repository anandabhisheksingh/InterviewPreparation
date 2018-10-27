// A Dynamic Programming based program to count exactly 'k' coins
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int pathCountDP(int mat[R][C], int m, int n, int k)
{
  int dp[m][n][k+1];

  int coinSum = 0;
  memset(dp, 0, sizeof dp);

  if (mat[0][0]>k){
    return 0;
  }

  dp[0][0][mat[0][0]]=1;

  // Allowed moves are only right and down
  for(int i=0; i<m; i++){

    coinSum +=  mat[i][0];

    if(coinSum<=k)
       dp[i][0][coinSum]=1;
  }

  coinSum=0;
  for(int i=0; i<n; i++){

    coinSum+=mat[0][i];
    if(coinSum<=k)
       dp[0][i][coinSum]=1;
  }

  for(int i=1; i<m; i++){
    for(int j=1; j<n; j++){
      for(int l=0; l<=k; l++){

        if (l-mat[i][j] >= 0)
            dp[i][j][l]=dp[i-1][j][l-mat[i][j]] + dp[i][j-1][l-mat[i][j]];
      }
    }
  }

  return dp[n-1][m-1][k];
}

// Driver Program to test above functions
int main()
{
  int k = 12;
  int mat[R][C] = { {1, 2, 3},
          {4, 6, 5},
          {3, 2, 1}
        };

  cout << pathCountDP(mat, R, C, k);
  return 0;
} 
