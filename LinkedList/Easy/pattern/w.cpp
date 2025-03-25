#include <iostream>
using namespace std;

int main()
{
  // Write C++ code here
  // std::cout << "Try programiz.pro";

  int n = 4;
  int c = 2 * n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i == j)
      {
        cout << "\\";
      }
      else if (j == c - i - 1)
      {
        cout << "/";
      }
      else
      {
        cout << " ";
      }
    }
    for (int j = 0; j < c; j++)
    {
      if (i == j)
      {
        cout << "\\";
      }
      else if (j == c - i - 1)
      {
        cout << "/";
      }
      else
      {
        if (j < c - i - 1) // removing the spaces from the last end
        {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  return 0;
}