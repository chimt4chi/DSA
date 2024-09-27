#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

// sorting, iterating, find

int main()
{
  array<int, 5> arr1{15, 10, 15, 200, 5};
  array<char, 5> arr2{'a', 'b', 'c', 'd', 'e'};

  sort(arr1.begin(), arr1.end()); // sorting

  // iterations
  for (auto i = arr1.begin(); i != arr1.end(); i++)
  { // using iterators
    cout << *i << " ";
  }
  cout << endl;

  for (auto i : arr1)
  { // range based
    cout << i << " ";
  }
  cout << endl;

  for (int i = 0; i < arr1.size(); i++)
  { // index based
    cout << arr1[i] << " ";
  }
  cout << endl;

  return 0;
}