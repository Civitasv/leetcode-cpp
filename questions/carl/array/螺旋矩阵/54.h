#pragma once

#include <vector>

using namespace std;

// TAG #数组 #矩阵 #模拟

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    int m = matrix.size(), n = matrix[0].size();
    int right = n - 1, down = m - 1, left = 0, up = 0;
    while (true) {
      // left -> right
      for (int i = left; i <= right; i++)
        result.push_back(matrix[up][i]);
      if (++up > down)
        break;
      // up -> down
      for (int i = up; i <= down; i++)
        result.push_back(matrix[i][right]);
      if (--right < left)
        break;
      // right -> left
      for (int i = right; i >= left; i--)
        result.push_back(matrix[down][i]);
      if (--down < up)
        break;
      // down -> up
      for (int i = down; i >= up; i--)
        result.push_back(matrix[i][left]);
      if (++left > right)
        break;
    }

    return result;
  }
};
