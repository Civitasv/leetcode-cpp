#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left{};
  TreeNode *right{};
  explicit TreeNode(int x) : val(x) {}
};

class Solution {
public:
  int rob(TreeNode *root) {
    auto val = robTree(root);
    return max(val.first, val.second);
  }

  /// @brief
  /// 抢劫当前树，能够盗取的最高金额
  /// @param node 树节点
  /// @return pair<int,int> first: 不偷取当前节点，second: 偷取当前节点
  pair<int, int> robTree(TreeNode *node) {
    if (node == nullptr)
      return {0, 0};

    int first = 0, second = 0;
    auto left = robTree(node->left);
    auto right = robTree(node->right);

    first = max(left.first, left.second) + max(right.first, right.second);
    second = left.first + right.first + node->val;

    return {first, second};
  }
};