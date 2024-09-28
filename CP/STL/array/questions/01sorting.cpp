#include <iostream>
#include <array>
using namespace std;

int main()
{
  // Question: Given an array of integers of length n, the task is to remove elements
  // from the array to make array sorted. That is, remove the elements which do not
  // follow an increasing order.
  array<int, 10> arr{1, 2, 4, 3, 5, 7, 8, 6, 9, 10};
  int size = arr.size();

  // Index to track the position of valid sorted elements
  int validIndex = 1; // Start with the first element already in place

  for (int i = 1; i < size; ++i)
  {
    // Only add elements that maintain the sorted order
    if (arr[i] > arr[validIndex - 1])
    {
      arr[validIndex] = arr[i];
      validIndex++;
    }
  }

  // Print the resulting array up to validIndex
  for (int i = 0; i < validIndex; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
