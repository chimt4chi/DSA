#include <bits/stdc++.h>
using namespace std;

int main()
{
  array<int, 5> arr{1, 2, 2, 4, 2};

  int x = 5;
  int size = arr.size();

  int firstIndex = -1;
  int lastIndex = -1;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == x)
    {
      if (firstIndex == -1)
      {
        firstIndex = i;
      }
      lastIndex = i;
    }
  }

  if (firstIndex != -1)
  {
    cout << firstIndex << endl;
    cout << lastIndex << endl;
  }
  else
  {
    cout << "Element not found." << endl;
  }

  return 0;
}