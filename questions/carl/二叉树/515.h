#pragma once
#include "./treenode.h"
#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> res;

    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int size = q.size();
      int max_val = INT32_MIN;
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        max_val = max(max_val, node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      res.push_back(max_val);
    }
    return res;
  }
};