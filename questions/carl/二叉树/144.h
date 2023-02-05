#pragma once
#include "./treenode.h"
#include <stack>
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

  // 迭代遍历
  vector<int> preorderTraversal2(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      if (node->right) {
        st.push(node->right);
      }
      if (node->left) {
        st.push(node->left);
      }
    }

    return res;
  }
};