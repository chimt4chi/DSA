// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

  vector<int> arr1{1, 2, 3, 4};
  vector<int> arr2{2, 3, 5, 6};
  set<int> temp; // set stores unique element

  for (auto i : arr1)
  {
    temp.insert(i); // insert arr1 element to temp set
  }

  for (auto i : arr2)
  {
    temp.insert(i); // insert arr2 element to temp set
  }
  cout << temp.size(); // returns the element count
  return 0;
}