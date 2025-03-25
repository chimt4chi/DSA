#include <iostream>
// #include <string>
using namespace std;
int main()
{
  // remove space from a string e.g. str = "Hello World"; //HelloWorld;

  string str = "H e l l o World";
  int len = str.length();
  // int space = str.find(' ');

  // str.erase(space, 1);

  string newStr;

  for (int i = 0; i < len; i++)
  {
    // char space = ' ';
    if (str[i] != ' ')
    {
      newStr += str[i];
    }
  }

  cout << newStr;

  // cout << str;

  return 0;
}