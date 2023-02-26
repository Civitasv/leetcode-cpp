// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/竞赛/334/6368.h"

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
  string word = "998244353";
  int m = 3;
  auto res = s.divisibilityArray(word, m);
  for (auto item : res)
    cout << item << ' ';

  return 0;
}
