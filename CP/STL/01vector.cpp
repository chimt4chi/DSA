#include <iostream>
#include <vector>
using namespace std;

int main()
{

  // Q: What is a vector?
  // A: Vector is a sequence container that is an array that can change its size dynamically. Unlike array the size of vector can be modified at the runtime.

  // vector<int> v;        // Declation of vector v.
  vector<int> v(5, 20); // vector v of int size of and 20 for each index
  v.push_back(1);       // adds the element in the end
  v.emplace_back(2);    // efficient than push_back()

  // cout << v.data(); // accessing the address
  // cout << v[3]; // accessing the value

  // cout << v.size(); // calculating the size

  // for(int i=0; i<v.size(); i++){
  //     cout << v[i];
  // }

  // for(vector<int>::iterator i = v.begin(); i != v.end(); i++){ // iterating through all the elements in the vector
  //     cout << *i;
  // }

  // iterators

  vector<int>::iterator i = v.begin();
  i++;
  cout << *i;

  return 0;
}