#pragma once
#include "./treenode.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;

    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int size = q.size();
      double val = 0.0;
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        val += node->val;

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      res.push_back(val / size);
    }
    return res;
  }
};