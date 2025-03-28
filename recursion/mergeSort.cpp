#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int mid, int low, int high)
{
  int n1 = mid - low + 1;   // size of left subarray
  int n2 = high - mid;      // size of right subarray
  vector<int> L(n1), R(n2); // temporary arrays

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[low + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }

  // merging

  int i = 0, j = 0, k = low;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // if some elements are still left

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    // divide
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    // merge
    merge(arr, mid, low, high);
  }
}

int main()
{
  vector<int> arr{4, 2, 6, 1, 9, 3, 5};
  int low = 0, high = arr.size() - 1;
  mergeSort(arr, low, high);
  for (auto i : arr)
  {
    cout << i << " ";
  }
  return 0;
}