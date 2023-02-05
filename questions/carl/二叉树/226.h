#pragma once
#include "./treenode.h"
#include <queue>
#include <vector>

class Solution {
public:
  TreeNode *helper(TreeNode *node) {
    if (node == nullptr) {
      return node;
    }
    TreeNode *left = node->left;
    node->left = helper(node->right);
    node->right = helper(left);
    return node;
  }

  TreeNode *invertTree(TreeNode *root) { return helper(root); }
};