#pragma once
#include "./treenode.h"

class Solution {
public:
  TreeNode *deleteOneNode(TreeNode *target) {
    if (target == nullptr) {
      return nullptr;
    }
    if (target->right == nullptr) {
      return target->left;
    }
    TreeNode *curr = target->right;
    while (curr->left)
      curr = curr->left;
    curr->left = target->left;
    return target->right;
  }

  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode *curr = root;
    TreeNode *parent = nullptr;
    while (curr && curr->val != key) {
      parent = curr;
      if (curr->val < key) {
        curr = curr->right;
      } else {
        curr = curr->left;
      }
    }
    if (parent == nullptr) {
      return deleteOneNode(curr);
    }
    if (parent->left && parent->left->val == key) {
      parent->left = deleteOneNode(curr);
    } else if (parent->right && parent->right->val == key) {
      parent->right = deleteOneNode(curr);
    }

    return root;
  }
};
