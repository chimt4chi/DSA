#include <bits/stdc++.h>
using namespace std;

// longest frequent integer (Run Length Encoding Algorithm)

int main()
{
  int arr[] = {2, 3, 4, 5, 1, 5, 6, 5, 6, 6, 6, 5, 6}; // 1,2,3,4,5,5,5,6
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }

  int index = arr[0];
  int res = 1;
  int count = 1;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == arr[i + 1])
    {
      count++;
    }
    else
    {
      count = 1;
    }
    if (count > res)
    {
      res++;
      index = arr[i];
    }
  };

  cout << index << ": " << res;

  return 0;
}