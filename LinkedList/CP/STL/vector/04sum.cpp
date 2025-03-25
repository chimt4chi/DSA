#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v{10, 20, 30, 40, 50};

  int sum = 0; // Initialize sum to 0

  for (auto i = v.begin(); i != v.end(); i++)
  {
    sum += *i; // Add each element to sum
  }

  cout << "Sum of elements: " << sum << endl; // Output the sum

  return 0;
}
