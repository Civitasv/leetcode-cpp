#pragma once
#include "./treenode.h"
#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr)
      return nullptr;
    if (val > root->val) {
      return searchBST(root->right, val);
    } else if (val < root->val) {
      return searchBST(root->left, val);
    } else
      return root;
  }
};
