#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int dp[nums.size()];
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (i >= 2)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      else
        dp[i] = max(dp[i - 1], nums[i]);
    }

    return dp[nums.size() - 1];
  }
};