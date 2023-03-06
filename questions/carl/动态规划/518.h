#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // 完全背包问题
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++)
      dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
        // cout << "dp[" << j << "]"
        //      << "+="
        //      << "dp[" << j - coins[i] << "]" << '\n';
      }
    }

    return dp[amount];
  }
};