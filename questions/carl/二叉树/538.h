#pragma once
#include "./treenode.h"
#include <vector>

using namespace std;

class Solution {
public:
  int sum = 0;
  TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    // 右，中，左
    root->right = convertBST(root->right);
    sum += root->val;
    root->val = sum;
    root->left = convertBST(root->left);
    return root;
  }
};
