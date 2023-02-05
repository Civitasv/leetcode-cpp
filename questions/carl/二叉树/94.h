#include "./treenode.h"
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
};