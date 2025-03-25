#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(11);
  // begin
  vector<int>::iterator b = v.begin();
  b++;
  cout << *b << endl;
  // end
  vector<int>::iterator e = v.end(); // this doesn't mean it is pointing to the last element but the address of the next element.
  e--;                               // this makes sure that the the element we are trying to access is the last element only
  cout << *e << endl;
  // rend
  vector<int>::reverse_iterator rb = v.rbegin(); // reverses the vector, iterates from last element, last element is first
  // re = re + 2;
  cout << "Reverse begin: " << *rb << endl;
  vector<int>::reverse_iterator re = v.rend(); // reverses the vector, iterates from last element, first element is last
  re = re - 1;
  cout << "Reverse end: " << *re << endl;
  // cout << *re;
  return 0;
}