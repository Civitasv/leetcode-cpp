#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { backTracking(board, 0, 0); }

  bool backTracking(vector<vector<char>>& board, int row, int col) {
    if (row == board.size() && col == 0) {
      return true;
    }

    if (board[row][col] != '.') {
      int new_row = row, new_col = col;
      if (new_col == board[0].size() - 1) {
        new_row++;
        new_col = 0;
      } else {
        new_col++;
      }

      return backTracking(board, new_row, new_col);
    }

    for (char c = '1'; c <= '9'; c++) {
      if (!isValid(board, row, col, c)) {
        continue;
      }
      board[row][col] = c;

      int new_row = row, new_col = col;
      if (new_col == board[0].size() - 1) {
        new_row++;
        new_col = 0;
      } else {
        new_col++;
      }

      if (backTracking(board, new_row, new_col)) return true;

      board[row][col] = '.';
    }
    return false;
  }

  bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // 规则 #1
    for (int j = 0; j < board[0].size(); j++) {
      if (board[row][j] == c) return false;
    }

    // 规则 #2
    for (int i = 0; i < board.size(); i++) {
      if (board[i][col] == c) return false;
    }

    // 规则 #3
    int region_row = (row / 3) * 3, region_col = (col / 3) * 3;
    for (int i = region_row; i < region_row + 3; i++) {
      for (int j = region_col; j < region_col + 3; j++)
        if (board[i][j] == c) return false;
    }
    return true;
  }
};