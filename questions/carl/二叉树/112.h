#pragma once

#include "./treenode.h"
#include <queue>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    // dfs
    stack<pair<TreeNode *, int>> st;
    if (root != nullptr)
      st.push({root, root->val});

    while (!st.empty()) {
      auto p = st.top();
      TreeNode *node = p.first;
      int val = p.second;
      st.pop();

      if (node->right)
        st.push({node->right, val + node->right->val});
      if (node->left)
        st.push({node->left, val + node->left->val});

      if (node->left == nullptr && node->right == nullptr) {
        if (val == targetSum)
          return true;
      }
    }

    return false;
  }
};
