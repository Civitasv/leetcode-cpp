#pragma once

#include "./treenode.h"
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  TreeNode *buildTree(const vector<int> &inorder,
                      const vector<int> &postorder) {
    if (inorder.size() == 0 || postorder.size() == 0)
      return nullptr;
    TreeNode *root = new TreeNode(*(postorder.end() - 1));

    vector<int> leftinorder;
    vector<int> leftpostorder;

    vector<int> rightinorder;
    vector<int> rightpostorder;

    int index = 0;
    for (index = 0; index < inorder.size(); index++) {
      if (inorder[index] == root->val)
        break;
    }

    for (int i = 0; i < index; i++) {
      leftinorder.push_back(inorder[i]);
      leftpostorder.push_back(postorder[i]);
    }

    for (int i = index + 1; i < inorder.size(); i++) {
      rightinorder.push_back(inorder[i]);
      rightpostorder.push_back(postorder[i - 1]);
    }

    root->left = buildTree(leftinorder, leftpostorder);
    root->right = buildTree(rightinorder, rightpostorder);

    return root;
  }
};
