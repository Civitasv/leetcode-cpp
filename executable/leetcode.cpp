// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/回溯/37.h"

// void Helper(TreeNode *node) {
//   if (node == nullptr) {
//     return;
//   }
//   cout << node->val << '\n';
//
//   cout << "left:: ";
//   Helper(node->left);
//   cout << "right:: ";
//   Helper(node->right);
// }

int main() {
  Solution s;
  vector<int> nums{3, 3, 0, 3};
  vector<vector<string>> n{
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  vector<vector<char>> cc = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  s.solveSudoku(cc);
  for (auto &item : cc) {
    for (auto &i : item) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}
