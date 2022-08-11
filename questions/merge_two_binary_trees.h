#pragma once

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    return helper(root1, root2);
  }
  TreeNode *helper(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return nullptr;
    TreeNode *node = new TreeNode();
    if (root1 != nullptr && root2 != nullptr) {
      node->val = root1->val + root2->val;
      node->left = helper(root1->left, root2->left);
      node->right = helper(root1->right, root2->right);
    } else if (root1 != nullptr) {
      node->val = root1->val;
      node->left = helper(root1->left, nullptr);
      node->right = helper(root1->right, nullptr);
    } else {
      node->val = root2->val;
      node->left = helper(root2->left, nullptr);
      node->right = helper(root2->right, nullptr);
    }
    return node;
  }
};