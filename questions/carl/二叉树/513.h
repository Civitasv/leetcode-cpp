#pragma once

#include "./treenode.h"
#include <queue>

using namespace std;

class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    int res = -1;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (i == 0)
          res = node->val;
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
    }

    return res;
  }
};
