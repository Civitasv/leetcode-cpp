#pragma once
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int dp[strs.size() + 1][m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++)
        dp[0][i][j] = 0;
    }

    for (int i = 1; i <= strs.size(); i++) {
      auto num = getZeroAndOneNum(strs[i-1]);
      int a = num.first;
      int b = num.second;
      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= n; k++) {
          if (j >= a && k >= b)
            dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - a][k - b] + 1);
          else
            dp[i][j][k] = dp[i - 1][j][k];
        }
      }
    }
    return dp[strs.size()][m][n];
  }

  pair<int, int> getZeroAndOneNum(const string &str) {
    int one = 0, zero = 0;
    for (const char c : str) {
      if (c == '1')
        one++;
      else
        zero++;
    }

    return {zero, one};
  }
};