#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  array<int, 10> arr{1, 2, 4, 3, 5, 7, 8, 6, 9, 10};
  vector<int> arr1(arr.begin(), arr.end());
  sort(arr1.begin(), arr1.end());

  // Print the resulting array up to validIndex
  for (int i = 0; i < 10; ++i)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;

  return 0;
}
