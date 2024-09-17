#include <iostream>
using namespace std;

int main()
{
  // print the number of words
  string S;
  getline(cin, S);
  int count = 1;

  for (int i = 0; i < S.length(); i++)
  {
    if (S[i] == ' ')
    {
      count++;
    }
  }

  cout << count;

  return 0;
}
