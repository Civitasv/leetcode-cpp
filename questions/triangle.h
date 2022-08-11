#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int size = triangle.size();
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
    for (int i = size - 1; i >= 0; --i) {
      for (int j = 0; j < triangle[i].size(); j++) {
        dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
      }
    }
    return dp[0][0];
  }
};