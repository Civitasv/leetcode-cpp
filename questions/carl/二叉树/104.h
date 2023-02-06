#pragma once
#include "./treenode.h"
#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);
    int max_depth = 0;
    while (!q.empty()) {
      int size = q.size();
      max_depth ++;
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return max_depth;
  }
};