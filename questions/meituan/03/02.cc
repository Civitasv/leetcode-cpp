#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> colors(n);
  for (int i = 0; i < n; i++) {
    cin >> colors[i];
  }
  vector<vector<int>> values(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> values[i][j];
    }
  }

  // Solve
  long max_val = INT32_MIN;
  vector<vector<long>> dp(n, vector<long>(m, 0));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0 && j > 0) {
        int down_cost = (colors[i - 1][j] == colors[i][j]) ? 0 : k;
        int right_cost = (colors[i][j - 1] == colors[i][j]) ? 0 : k;
        bool can_down = (dp[i - 1][j] != -1) && (dp[i - 1][j] >= down_cost);
        bool can_right = (dp[i][j - 1] != -1) && (dp[i][j - 1] >= right_cost);
        if (can_down && can_right) {
          dp[i][j] = max(dp[i - 1][j] - down_cost + values[i][j],
                         dp[i][j - 1] - right_cost + values[i][j]);
        } else if (!can_down && can_right) {
          dp[i][j] = dp[i][j - 1] - right_cost + values[i][j];
        } else if (can_down && !can_right) {
          dp[i][j] = dp[i - 1][j] - down_cost + values[i][j];
        } else {
          dp[i][j] = -1; // 表示这里不合法
        }
      } else if (i == 0 && j == 0) {
        dp[i][j] = values[i][j];
      } else if (i == 0) {
        int right_cost = (colors[i][j - 1] == colors[i][j]) ? 0 : k;
        bool can_right = (dp[i][j - 1] != -1) && (dp[i][j - 1] >= right_cost);
        if (can_right) {
          dp[i][j] = dp[i][j - 1] - right_cost + values[i][j];
        } else {
          dp[i][j] = -1;
        }
      } else if (j == 0) {
        int down_cost = (colors[i - 1][j] == colors[i][j]) ? 0 : k;
        bool can_down = (dp[i - 1][j] != -1) && (dp[i - 1][j] >= down_cost);
        if (can_down) {
          dp[i][j] = dp[i - 1][j] - down_cost + values[i][j];
        } else {
          dp[i][j] = -1;
        }
      }

      max_val = max(max_val, dp[i][j]);
    }
  }

  cout << max_val << '\n';

  return 0;
}