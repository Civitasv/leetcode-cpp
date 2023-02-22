// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/二叉树/654.h"
using namespace std;

void helper(TreeNode *node) {
  if (node == nullptr)
    return;
  cout << node->val << " ";

  cout << "left:: ";
  helper(node->left);
  cout << "right:: ";
  helper(node->right);
}
int main() {
  Solution s;
  vector<int> x{3, 2, 1, 6, 0, 5};
  auto res = s.constructMaximumBinaryTree(x);

  helper(res);
  return 0;
}
