#include <iostream>
using namespace std;

int main()
{
  int r, c;
  cout << "Enter Rows: ";
  cin >> r;
  cout << "Enter Columns: ";
  cin >> c;

  cout << "Enter elements to insert into the matrix: ";
  int arr[r][c];

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr[i][j];
    }
    cout << endl;
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << arr[i][j];
      // cout << arr[j][i];
    }
    cout << endl;
  }

  cout << endl;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      // cout << arr[i][j];
      cout << arr[j][i];
    }
    cout << endl;
  }

  return 0;
}