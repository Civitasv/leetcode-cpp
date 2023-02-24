// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/二叉树/108.h"
using namespace std;

void helper(TreeNode *node) {
  if (node == nullptr)
    return;
  cout << node->val << '\n';

  cout << "left:: ";
  helper(node->left);
  cout << "right:: ";
  helper(node->right);
}

int main() {
  Solution s;
  TreeNode a_node(1);
  // TreeNode a_node1(3);
  TreeNode a_node2(2);
  TreeNode a_node3(2);
  // a_node.left = &a_node1;
  a_node.right = &a_node2;
  a_node2.left = &a_node3;

  TreeNode b_node(2);
  TreeNode b_node1(1);
  TreeNode b_node2(3);
  TreeNode b_node3(4);
  TreeNode b_node4(7);
  b_node.left = &b_node1;
  b_node.right = &b_node2;
  b_node1.right = &b_node3;
  b_node2.right = &b_node4;

  vector<int> nums {-10,-3,0,5,9};
  auto res = s.sortedArrayToBST(nums);

  helper(res);
  return 0;
}
