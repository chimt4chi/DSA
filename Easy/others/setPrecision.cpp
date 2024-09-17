#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // print the precision
  double num = 3.1341231;
  cout << fixed << setprecision(3) << num;
  // cout << num;
  return 0;
}