// Question: calculate power (n) of x using recursion

#include <iostream>
using namespace std;

int powOfN(int x, int n)
{
  // cout << n;
  if (n == 0)
    return 1;
  return x * powOfN(x, n - 1);
}

int main()
{
  int x = 2, n = 3;
  cout << powOfN(x, n);
  return 0;
}