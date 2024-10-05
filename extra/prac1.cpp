#include <iostream>
using namespace std;
int fact(int n)
{
  int sum = 1;
  for (int i = 0; i < n; i++)
  {
    sum = i * n;
  }
  return sum;
}
int main()
{
  int n;
  cin >> n;
  cout << fact(5);
  return 0;
}