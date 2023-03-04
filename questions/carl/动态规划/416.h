#pragma once
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    // 转化为 0-1 背包问题：验证是否存在背包，其内所有元素的和是 sum/2
    int sum = 0;
    for (auto num : nums)
      sum += num;
    if (sum % 2 == 1)
      return false;
    bool dp[nums.size()]
           [sum / 2 + 1]; // dp[i][j] 表示是否存在 nums[0, i] 取元素，和为 j
    // 动规公式：dp[i][j] = dp[i-1][j], dp[i - 1][j-nums[i]]
    // 初始化
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j <= sum / 2; j++)
        dp[i][j] = false;
    }
    for (int j = 0; j <= sum / 2; j++) {
      dp[0][j] = nums[0]==j;
    }
    // 状态变化
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j <= sum / 2; j++) {
        if (j < nums[i])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
      }
    }

    return dp[nums.size() - 1][sum / 2];
  }
};