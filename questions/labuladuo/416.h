#pragma once
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for_each(nums.begin(), nums.end(), [&](int num) { sum += num; });
    if (sum % 2 != 0)
      return false;
    bool dp[nums.size()][sum / 2 + 1];
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j <= sum / 2; j++) {
        if (i == 0) {
          dp[0][j] = j == nums[0];
        } else if (j < nums[i])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
      }
    }
    return dp[nums.size() - 1][sum / 2];
  }
};