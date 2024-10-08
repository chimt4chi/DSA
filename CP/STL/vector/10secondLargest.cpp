#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int getSecondLargest(vector<int> &arr)
{
  sort(arr.rbegin(), arr.rend());

  auto last = unique(arr.begin(), arr.end());

  arr.erase(last, arr.end());

  int size = arr.size();

  int secLarge = 0;

  if (size == 1)
  {
    secLarge = -1;
  }
  else
  {
    secLarge = arr[1];
  }

  return secLarge;
}

int main()
{
  vector<int> arr{10, 2, 10};
  cout << getSecondLargest(arr);
  return 0;
}