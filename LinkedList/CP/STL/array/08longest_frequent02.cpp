#include <bits/stdc++.h>
using namespace std;

// longest frequent integer (using map)

int main()
{
  int arr[] = {2, 3, 4, 5, 1, 5, 6, 5, 6, 6, 6, 5, 6}; // 1,2,3,4,5,5,5,6
  map<int, int> kvp;
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++)
  {
    kvp[arr[i]]++;
  }

  int maxCount = 0;
  int res = 0;

  for (auto i : kvp)
  {
    if (i.second > maxCount)
    {
      maxCount = i.second;
      res = i.first;
    }
  }

  cout << res << ": " << maxCount;

  return 0;
}