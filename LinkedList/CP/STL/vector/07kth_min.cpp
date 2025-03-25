#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> arr{7, 10, 4, 3, 20, 15}; // target vector array.
  int k = 4;                            // expected element.
  sort(arr.begin(), arr.end());         // imported from algorithm library.
  int size = arr.size();                // size of the vector.
  for (int i = 0; i < size; i++)
  {
    int oneless = k - 1;  // index based loop starts from 0 hence k - 1.
    cout << arr[oneless]; // this might return the expected output many times.
    return arr[oneless];  // this will return the expected output only once.
  }

  return 0;
}