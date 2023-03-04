// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/05_02.h"

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
  cout << s.printBin(0.625) << endl;
}
