#pragma once
#include "./treenode.h"
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == p || root == q || root == nullptr)
      return root;
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;
    if (left && right == nullptr) {
      return left;
    }

    if (right && left == nullptr) {
      return right;
    }
    return nullptr;
  }
};
