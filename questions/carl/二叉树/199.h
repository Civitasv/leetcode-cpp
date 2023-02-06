#pragma once
#include "./treenode.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;

    queue<TreeNode *> dq;
    dq.push(root);

    while (!dq.empty()) {
      int size = dq.size();
      for (int i = 0; i < size - 1; i++) {
        TreeNode *node = dq.front();
        dq.pop();
        if (node->left)
          dq.push(node->left);
        if (node->right)
          dq.push(node->right);
      }
      TreeNode *node = dq.front();
      dq.pop();
      res.push_back(node->val);
      if (node->left)
        dq.push(node->left);
      if (node->right)
        dq.push(node->right);
    }
    return res;
  }
};