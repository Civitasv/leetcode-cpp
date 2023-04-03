#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);

    int a = robRange(nums, 0, nums.size() - 2);
    int b = robRange(nums, 1, nums.size() - 1);

    return max(a, b);
  }

  int robRange(vector<int> &nums, int i, int j) {
    int dp[j - i + 1];
    dp[0] = nums[i];
    dp[1] = max(nums[i], nums[i + 1]);

    for (int k = i + 2; k <= j; k++) {
      dp[k - i] = max(dp[k - i - 1], dp[k - i - 2] + nums[k]);
    }

    return dp[j - i];
  }
};