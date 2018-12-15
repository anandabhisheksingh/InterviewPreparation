// https://www.geeksforgeeks.org/shuffle-array-a1-b1-a2-b2-a3-b3-bn-without-using-extra-space/
#include <bits/stdc++.h>
using namespace std;

// Shuffles an array of size 2n
void shufleArray(int a[], int n)
{
  n = n / 2;

  // We have to do traverse array for 2n – 2 times, assuming that n = half of length of array.
  // Since first and last numbers don’t move from their places.
  int range = 2 * n - 2;

  for (int start = n, j = n, count = 0; count < range; count++) {

    // Index are same it means a[j] is at correct position, so change 'j' and 'start'
    if (start == j) {
      start--;
      j--;
    }

    // Keep track of the index from which any number is picked. If a_i picked, it has to go to the index 2*i
    // and if b_i, it has to go at 2*(j - n) + 1 in the final array. If 'j' < 'n' than it belongs to first
    // half i.e. 'a_x' else it belongs to second half i.e. 'b_x'
    j = j > n ? 2*(j - n) + 1: 2 * j;
    j = j % (2*n-1);

    swap(a[start], a[j]);
  }
}

// Driven Program
int main()
{
  int a[] = {1, 3, 5, 7, 2, 4, 6, 8 };
  int n = sizeof(a) / sizeof(a[0]);

  shufleArray(a, n);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  return 0;
}
