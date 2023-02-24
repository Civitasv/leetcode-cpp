#pragma once
#include "./treenode.h"
#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    return helper(root1, root2);
  }

  TreeNode *helper(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr) {
      return nullptr;
    }
    if (node1 != nullptr && node2 != nullptr) {
      TreeNode *node = new TreeNode(node1->val + node2->val);
      node->left = helper(node1->left, node2->left);
      node->right = helper(node1->right, node2->right);
      return node;
    } else if (node1 == nullptr) {
      TreeNode *node = new TreeNode(node2->val);
      node->left = helper(node1, node2->left);
      node->right = helper(node1, node2->right);
      return node;
    } else /*if (node2 == nullptr)*/ {
      TreeNode *node = new TreeNode(node1->val);
      node->left = helper(node1->left, node2);
      node->right = helper(node1->right, node2);
      return node;
    }
  }
};
