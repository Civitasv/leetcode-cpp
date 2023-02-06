#include "./treenode.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  void helper(TreeNode *node, vector<int> &res) {
    if (!node)
      return;
    helper(node->left, res);
    res.push_back(node->val);
    helper(node->right, res);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    helper(root, res);
    return res;
  }

  // 迭代遍历
  vector<int> inorderTraversal2(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<TreeNode *> st;

    TreeNode *node = root;
    while (node != nullptr || !st.empty()) {
      if (node != nullptr) {
        st.push(node); // 左
        node = node->left;
      } else {
        node = st.top();
        st.pop();

        res.push_back(node->val); // 中
        node = node->right; // 右
      }
    }

    return res;
  }
};
;
