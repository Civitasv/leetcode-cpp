// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/动态规划/474.h"

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
  vector<int> coins{1, 2, 5};
  vector<string> strs{"10", "0001", "111001", "1", "0"};
  cout << s.findMaxForm(strs, 5, 3);
}
