#include <iostream>
using namespace std;

int countSquares(int N)
{
  // code here
  int count = 0;
  int i = 1;
  if (N < 1)
  {
    return 0;
  }
  else
  {
    while (i * i < N)
    {
      count++;
      i++;
    }
  }
  return count;
}

int main()
{
  cout << countSquares(9);
}