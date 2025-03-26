#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int climbStairsHelper(int n, vector<int> &dp)
  {
    if (n < 0)
      return 0;
    if (n == 0)
      return 1;
    if (dp[n] != -1)
      return dp[n]; // avoiding re calculation
    return dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
  }

  int climbStairs(int n)
  {
    vector<int> dp(n + 1, -1);
    return climbStairsHelper(n, dp);

    // TC - O(2n) SC - O(n) due to repeated calculations
    // if(n < 0) return 0;
    // if(n == 0) return 1;
    // return climbStairs(n - 1) + climbStairs(n-2);
  }
};
