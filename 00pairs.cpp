#include <iostream>
using namespace std;

int main()
{
  // pair is part of utility library
  pair<int, int> p = {1, 3};

    // accessing values from the p variable
  // cout << p.second;
  // cout << arr[2].first;

  // Creating a pair of array
  pair<int, int> arr[] = {{0, 1}, {2, 3}, {4, 5}, {6, 8}}; // need to have 2 pairs only
  int size = sizeof(arr) / sizeof(arr[0]);                 // calculating the size
  // Looping the pair of array
  for (int i = 0; i < size; i++)
  {
    cout << arr[i].first;
    cout << arr[i].second;
  }

  return 0;
}