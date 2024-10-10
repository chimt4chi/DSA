#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{

  vector<int> v{0, 2, 1, 2, 0};

  int size = v.size();

  int zero = 0;
  int ones = 0;
  int twos = 0;

  for (auto i : v)
  {
    if (i == 0)
    {
      zero++;
    }
    else if (i == 1)
    {
      ones++;
    }
    else
    {
      twos++;
    }
  }

  cout << "Before: " << endl;
  cout << ones << " " << ones << " " << twos << " ";

  sort(v.begin(), v.end());

  v.erase(v.begin(), v.end());

  for (int i = 0; i < zero; i++)
  {
    v.push_back(0);
  }

  for (int i = 0; i < ones; i++)
  {
    v.push_back(1);
  }

  for (int i = 0; i < twos; i++)
  {
    v.push_back(2);
  }

  cout << "After: \n";

  for (auto i : v)
  {
    cout << i << " ";
  }

  return 0;
}