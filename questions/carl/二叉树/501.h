#pragma once
#include "./treenode.h"
#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *pre = nullptr;
  int count = 0;
  int max_count = 0;
  vector<int> findMode(TreeNode *root) {
    // 中序遍历和二叉搜索树很配
    vector<int> v;
    helper(v, root);
    return v;
  }

  void helper(vector<int> &v, TreeNode *node) {
    if (node == nullptr)
      return;

    helper(v, node->left);

    if (pre) {
      if (pre->val == node->val) {
        count++;
      } else {
        count = 1;
      }
    } else {
      count = 1;
    }
    pre = node;

    if (count > max_count) {
      max_count = count;
      v.clear();
      v.push_back(pre->val);
    } else if (count == max_count) {
      v.push_back(pre->val);
    }

    helper(v, node->right);
  }
};
