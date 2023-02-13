#pragma once
#include <queue>

#include "./treenode.h"
using namespace std;

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    /* return helper(root->left, root->right); */
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
      auto left = q.front();
      q.pop();
      auto right = q.front();
      q.pop();
      if (left == nullptr && right == nullptr) continue;
      if (left == nullptr || right == nullptr) return false;
      if (left->val != right->val) return false;
      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }
    return true;
  }

  bool helper(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;

    return left->val == right->val && helper(left->left, right->right) &&
           helper(left->right, right->left);
  }
};