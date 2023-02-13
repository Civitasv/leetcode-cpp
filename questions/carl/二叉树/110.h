#pragma once
#include <cstdint>
#include <queue>
#include <vector>

#include "./treenode.h"
using namespace std;

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    return getHeight(root) == -1 ? false : true;
  }

  int getHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_height = getHeight(node->left);
    if (left_height == -1) return -1;
    int right_height = getHeight(node->right);
    if (right_height == -1) return -1;
    return abs(left_height - right_height) > 1
               ? -1
               : 1 + max(left_height, right_height);
  }
};