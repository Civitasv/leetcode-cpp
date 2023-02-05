#pragma once
#include "./treenode.h"
#include <vector>

using namespace std;

class Solution {
public:
  void helper(TreeNode *node, vector<int> &res) {
    if (!node)
      return;
    res.push_back(node->val);
    helper(node->left, res);
    helper(node->right, res);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
};