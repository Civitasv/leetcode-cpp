#pragma once
#include "./treenode.h"
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *pre = nullptr;
  int getMinimumDifference(TreeNode *root) {
    // 二叉搜索树是有序的，所以中序遍历
    int val = INT_MAX;
    if (root == nullptr)
      return val;

    int left = getMinimumDifference(root->left);

    if (pre) {
      val = root->val - pre->val;
    }
    pre = root;

    int right = getMinimumDifference(root->right);

    return min(min(val, left), right);
  }
};
