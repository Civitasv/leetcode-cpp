// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/回溯/47.h"

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
  vector<int> nums{3,3,0,3};
  auto res = s.permuteUnique(nums);
  for (auto item : res) {
    for (auto i : item)
      cout << i << ' ';
    cout << '\n';
  }

  return 0;
}
