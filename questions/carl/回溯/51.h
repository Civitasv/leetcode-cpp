#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> item(n, string(n, '.'));
    backTracking(result, item, 0, n);
    return result;
  }

  void backTracking(vector<vector<string>>& result, vector<string>& item,
                    int row, int n) {
    if (row == n) {
      result.push_back(item);
      return;
    }

    for (int col = 0; col < n; col++) {
      if (!isValid(row, col, item, n)) {
        continue;
      }
      item[row][col] = 'Q';
      backTracking(result, item, row + 1, n);
      item[row][col] = '.';
    }
  }

  bool isValid(int row, int col, vector<string>& item, int n) {
    // 竖线
    for (int i = 0; i < row; i++) {
      if (item[i][col] == 'Q') return false;
    }
    // 45 度
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (item[i][j] == 'Q') return false;
    }
    // 135 度
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (item[i][j] == 'Q') return false;
    }
    return true;
  }
};