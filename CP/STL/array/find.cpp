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

  for (auto i : arr1)
  { // range based
    cout << i << " ";
  }
  cout << endl;

  // auto n = find(arr1.begin(), arr1.end(), 15); // find(start, end, varible)
  char toFind = 'f';                               // target
  auto n = find(arr2.begin(), arr2.end(), toFind); // find(start, end, varible)

  if (n != arr2.end())
  {
    cout << *n << endl;
  }
  else
  {
    cout << toFind << " not found";
  }
  cout << endl;

  return 0;
}