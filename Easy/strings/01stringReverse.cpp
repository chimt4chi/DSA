#include <iostream>
// #include <string>
using namespace std;
int main()
{
  // Reverse a string
  string str = "Rohit";
  int start = 0, end = str.size() - 1;

  while (start < end)
  {
    // method 1 - using inbuilt swap function

    // swap(str[start], str[end]);

    // Method 2 - creating swap functionality to swap the char
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++, end--;
  }

  cout << str;
  return 0;
}