#include <iostream>
#include <vector>
using namespace std;

void reverseArr(vector<int> &arr)
{
  int size = arr.size();
  for (int i = 0; i < size / 2; i++)
  {
    swap(arr[i], arr[size - 1 - i]);
  }
}

int main()
{
  vector<int> arr{1, 2, 3, 4};

  reverseArr(arr);

  for (auto i : arr)
  {
    cout << i << " ";
  }

  return 0;
}