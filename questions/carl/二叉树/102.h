#include "./treenode.h"
#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;

    deque<TreeNode *> dq;
    dq.push_back(root);

    while (!dq.empty()) {
      vector<int> item;
      int size = dq.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = dq.front();
        dq.pop_front();
        item.push_back(node->val);

        if (node->left)
          dq.push_back(node->left);
        if (node->right)
          dq.push_back(node->right);
      }
      res.push_back(item);
    }
    return res;
  }
};