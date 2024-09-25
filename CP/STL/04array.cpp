#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
  array<int, 4> arr{1, 23, 4, 5};

  int size = arr.size();
  // cout << size;
  auto first = arr.begin();
  auto last = arr.end();
  sort(arr.begin(), arr.end());
  // cout << arr.begin(); // returns address of the first element since it is a pointer
  // cout << arr.cbegin(); // same as begin() but with read only
  // cout << arr.crbegin();
  for (auto it = arr.begin(); it != arr.end(); it++)
  {
    // cannot modify with crbegin, or crend and cbegin, cend;
    // being() to end() returns sorted array in increasing order
    // rbegin() to rend() returns sorted array in descending order
    // *it += 10;
    cout << *it << " ";
  }
  cout << endl;

  arr.front() = 7; // modifying first element to 7
  arr.back() = 7;  // modifying last element to 7

  for (auto it = arr.begin(); it != arr.end(); it++)
  {
    *it += 10;
    // arr.at(i) = arr[i] + 10;
    // cout << arr.at(it) << " ";
    cout << *it << " ";
  }
  cout << endl;

  cout << arr.front() << endl; // returns the first element in the array

  cout << *arr.data() << " "; // returns the first element in the array cuz array are stored in contiguous manner

  return 0;
}