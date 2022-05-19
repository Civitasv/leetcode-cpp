#include <iostream>
#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        std::vector<int> dp(n, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

