#pragma once

#include <vector>

using namespace std;

// TAG #数组 #矩阵 #模拟

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int left = 0, right = n - 1, up = 0, down = n - 1;
    int v = 1;
    while (true) {
      for (int i = left; i <= right; i++)
        res[up][i] = v++;

      if (++up > down)
        break;

      for (int i = up; i <= down; i++)
        res[i][right] = v++;

      if (--right < left)
        break;

      for (int i = right; i >= left; i--)
        res[down][i] = v++;

      if (--down < up)
        break;

      for (int i = down; i >= up; i--)
        res[i][left] = v++;

      if (++left > right)
        break;
    }
    return res;
  }
};
