#pragma once

#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int dp[nums.size()][2];
    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i < nums.size(); i++) {
      dp[i][0] = dp[i][1] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] > nums[i])
          dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        if (nums[j] < nums[i])
          dp[i][1] = max(dp[i][1], dp[j][0] + 1);
      }
    }

    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
  }
};