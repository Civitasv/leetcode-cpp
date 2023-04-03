#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for_each(nums.begin(), nums.end(), [&sum](int num) { sum += num; });
    if (sum < abs(target) || (sum + target) % 2 != 0)
      return 0;
    // dp[i][j] 表示从数组 nums[0,..i) 中取值，和为j的数目
    vector<vector<int>> dp(nums.size() + 1,
                           vector<int>((sum + target) / 2 + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 0; j <= (sum + target) / 2; j++) {
        if (j < nums[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
      }
    }
    return dp[nums.size()][(sum + target) / 2];
  }
};