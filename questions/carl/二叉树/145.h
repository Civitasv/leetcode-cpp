#include "./treenode.h"
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  void helper(TreeNode *node, vector<int> &res) {
    if (!node)
      return;
    helper(node->left, res);
    helper(node->right, res);
    res.push_back(node->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    helper(root, res);
    return res;
  }

  // 迭代遍历
  vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      if (node->left) {
        st.push(node->left);
      }
      if (node->right) {
        st.push(node->right);
      }
    }
    reverse(res.begin(), res.end());

    return res;
  }
};