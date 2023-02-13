#pragma once
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "./treenode.h"
using namespace std;

class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    getPath(res, root, to_string(root->val));
    return res;
  }

  void getPath(vector<string>& res, TreeNode* node, string path) {
    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(path);
    }

    if (node->left != nullptr) {
      getPath(res, node->left, path + "->" + to_string(node->left->val));
    }

    if (node->right != nullptr) {
      getPath(res, node->right, path + "->" + to_string(node->right->val));
    }
  }
};