#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
  array<int, 5> arr = {11, 6, 3, 2, 5};
  // cout << arr[1];
  // arr.push_back(5);
  arr[3] = 1;
  cout << "Before Sorting" << endl;
  int start = 1;
  for (auto i : arr)
  {
    // i += 1;
    cout << i;
    if (start < arr.size())
    {
      cout << ",";
    }
    start++;
  }
  cout << endl;
  // cout << *arr.end() - 1;
  cout << "After Sorting" << endl;
  sort(arr.begin(), arr.end()); // sort from the start to the end.
  for (auto i : arr)            // automatically identifies the data type
  {
    static int sstart = 1;
    // i += 1;
    cout << i;
    if (sstart < arr.size())
    {
      cout << ",";
    }

    sstart++;
  }

  cout << endl;

  cout << "Max Size: " << arr.max_size() << endl;
  cout << "Size: " << arr.size() << endl;
  return 0;
}