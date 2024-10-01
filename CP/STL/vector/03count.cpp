#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v{10, 20, 30, 40, 10};

  // int count = 0;

  // for(auto i = v.begin(); i != v.end(); i++){
  //     if(*i == 10){
  //         count++;
  //     }
  // }

  // alternate method

  int c = count(v.begin(), v.end(), 10);

  cout << c;

  return 0;
}
