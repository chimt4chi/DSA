#include <iostream>
#include <cmath>
using namespace std;

// Q. refer image to understand more on what this questions is

int main()
{
  // write your code here
  int n, m;
  cin >> n;
  cin >> m;
  int arr[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  int sum1 = 0, sum2 = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i < n / 2 && j == 0)
      {
        sum1 += arr[i][j];
      }
      if (i == n / 2 && j == j)
      {
        sum1 += arr[i][j];
      }
      if (i >= n / 2 + 1 && j == m - 1)
      {
        sum1 += arr[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 && j >= m / 2)
      {
        sum2 += arr[i][j];
      }
      if (i > 0 && i < n - 1 && j == m / 2)
      {
        sum2 += arr[i][j];
        // cout << arr[i][j] << " ";
      }
      if (i == n - 1 && j <= m / 2)
      {
        // cout << arr[i][j] << " ";
        sum2 += arr[i][j];
        // cout << arr[i][j] << " ";
      }
    }
  }

  cout << abs(sum1 - sum2);

  return 0;
}
