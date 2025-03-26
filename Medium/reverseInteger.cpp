// Q7. Reverse Integer.
// https://leetcode.com/problems/reverse-integer/description/
#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
  long int reversed = 0;
  while (n > 0)
  {
    int last = n % 10;                            // extracting the last number
    reversed = reversed * 10 + last;              // storing last
    if (reversed > INT_MAX || reversed < INT_MIN) // if reverse exceeds the infite -,+.
      return 0;
    n /= 10; // remove the last number from the n
  }

  return reversed;
}

int main()
{
  int n = -123;
  cout << reverse(n);
  return 0;
}