#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // std::cout << "Hello world!" << std::endl;
  vector<int> v1{5, 1, 2};
  vector<int> v2{10, 3, 4, 2, 12};
  int v1_size_previous = v1.size();
  v1.insert(v1.end(), v2.begin(), v2.end());

  sort(v1.begin(), v1.end());

  for (auto i : v1)
  {
    cout << i << " ";
  }

  cout << endl;

  for (auto i : v2)
  {
    cout << i << " ";
  }

  cout << endl;

  cout << v1.size();

  // Note: v2 is still the same vector.
  return 0;
}