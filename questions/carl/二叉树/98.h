#pragma once
#include "./treenode.h"
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *pre = nullptr;
  bool isValidBST(TreeNode *root) {
    // 二叉搜索树一定是有序的
    if (!root)
      return true;

    bool left = isValidBST(root->left);

    if (pre && pre->val >= root->val)
      return false;
    pre = root;

    bool right = isValidBST(root->right);
    return left && right;
  }
};
