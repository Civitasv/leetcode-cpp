#pragma once

#include "./treenode.h"
#include <queue>

using namespace std;

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        TreeNode *left = node->left;

        if (left != nullptr && left->left == nullptr &&
            left->right == nullptr) {
          sum += left->val;
        }

        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
    }
    return sum;
  }
};
