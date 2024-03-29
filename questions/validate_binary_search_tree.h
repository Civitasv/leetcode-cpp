#pragma once
#include <cstdint>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
public:
  int last = INT32_MIN;

  bool isValidBST(TreeNode *root) {
    // 中序遍历为升序
    if (root == nullptr) {
      return true;
    }
    // left
    bool left_valid = isValidBST(root->left);
    if (left_valid) {
      // mid
      int root_val = root->val;
      // left must less than mid
      if (last < root_val) {
        last = root_val;
        return isValidBST(root->right);
      }
    }

    return false;
  }
};
