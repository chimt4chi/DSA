#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v{10, 20, 30, 40, 50};

  int n = v.size();
  for (int i = 0; i < n / 2; i++)
  {
    swap(v[i], v[n - i - 1]); // Swap elements
  }

  for (auto i = v.begin(); i != v.end(); i++)
  {
    cout << *i << " ";
  }

  // alternate method

  reverse(v.begin(), v.end());

  for (auto i = v.begin(); i != v.end(); i++)
  {
    cout << *i << " ";
  }

  return 0;
}
