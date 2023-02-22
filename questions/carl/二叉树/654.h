#pragma once

#include "./treenode.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return helper(nums, nums.begin(), nums.end() - 1);
  }

  TreeNode *helper(vector<int> &nums, const vector<int>::const_iterator &begin,
                   const vector<int>::const_iterator &end) {
    if (begin > end) {
      return nullptr;
    }
    auto ele = max_element(begin, end + 1);
    TreeNode *root = new TreeNode(*ele);

    root->left = helper(nums, begin, ele - 1);
    root->right = helper(nums, ele + 1, end);

    return root;
  }
};
