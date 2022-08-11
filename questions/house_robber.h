#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    int length = nums.size();
    if (length == 1) {
      return nums[0];
    }
    vector<int> dp(length, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < length; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[length - 1];
  }
};