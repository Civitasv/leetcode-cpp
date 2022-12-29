#pragma once

#include <vector>

using namespace std;

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix)
      : pre_sum(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        sum += matrix[i][j];
        pre_sum[i + 1][j + 1] = pre_sum[i][j + 1] + sum;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return pre_sum[row2 + 1][col2 + 1] + pre_sum[row1][col1] -
           pre_sum[row2 + 1][col1] - pre_sum[row1][col2 + 1];
  }

 private:
  vector<vector<int>> pre_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */