#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v{10, 20, 30, 40, 50};
  int num = v[0];
  for (auto i = v.begin() + 1; i != v.end(); i++)
  {
    if (num < *i)
      num = *i;
  }

  cout << num;

  return 0;
}
