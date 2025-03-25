#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr{1, -1, 3, 2, -7, 0, -5, 11, 6, 0};
  vector<int> arr1{};

  for (auto i : arr)
  {
    if (i >= 0)
    {
      arr1.push_back(i);
    }
  }

  for (auto i : arr)
  {
    if (i < 0)
    {
      arr1.push_back(i);
    }
  }

  arr.erase(arr.begin(), arr.end());

  for (auto i : arr1)
  {
    arr.push_back(i);
  }

  for (auto i : arr)
  {
    cout << i << " ";
  }

  return 0;
}