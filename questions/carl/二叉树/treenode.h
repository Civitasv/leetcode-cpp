#pragma once

struct TreeNode {
  int val;
  TreeNode* left{};
  TreeNode* right{};
  explicit TreeNode(int x) : val(x)  {}
};
