#pragma once
#include "./treenode.h"
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }

  TreeNode *helper(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }

    int index = (start + end) / 2;
    TreeNode *node = new TreeNode(nums[index]);
    node->left = helper(nums, start, index - 1);
    node->right = helper(nums, index + 1, end);
    return node;
  }
};
