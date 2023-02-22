#pragma once

#include "./treenode.h"
#include <queue>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
      return {};
    vector<vector<int>> result;
    vector<int> item{root->val};

    backTracking(result, item, root, root->val, targetSum);

    return result;
  }

  void backTracking(vector<vector<int>> &result, vector<int> &item,
                    TreeNode *curr, int sum, int target) {
    if (curr->left == nullptr && curr->right == nullptr) {
      if (sum == target) {
        result.push_back(item);
      }
      return;
    }

    if (curr->left) {
      item.push_back(curr->left->val);
      sum += curr->left->val;
      backTracking(result, item, curr->left, sum, target);
      item.pop_back();
      sum -= curr->left->val;
    }
    if (curr->right) {
      item.push_back(curr->right->val);
      sum += curr->right->val;
      backTracking(result, item, curr->right, sum, target);
      item.pop_back();
      sum -= curr->right->val;
    }
  }
};
