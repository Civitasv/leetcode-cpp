#pragma once
#include <cstdint>
#include <queue>
#include <vector>

#include "./treenode.h"
using namespace std;

class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};