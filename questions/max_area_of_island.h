#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int max_area = 0;
    vector<vector<bool>> vi(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (vi[i][j]) continue;
        if (grid[i][j] == 1) {
          int area = 0;
          helper(grid, vi, area, i, j);
          max_area = max(max_area, area);
        }
      }
    }
    return max_area;
  }

  void helper(vector<vector<int>> &grid, vector<vector<bool>> &vi, int &count,
              int sr, int sc) {
    if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() ||
        grid[sr][sc] != 1 || vi[sr][sc])
      return;
    count++;
    vi[sr][sc] = true;
    helper(grid, vi, count, sr, sc + 1);  // right
    helper(grid, vi, count, sr, sc - 1);  // left
    helper(grid, vi, count, sr + 1, sc);  // down
    helper(grid, vi, count, sr - 1, sc);  // up
  }
};
