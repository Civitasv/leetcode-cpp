#pragma once

#include <queue>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    queue<Node *> q;

    if (root)
      q.push(root);

    while (!q.empty()) {
      vector<int> item;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        item.push_back(node->val);
        for (Node *item : node->children) {
          if (item)
            q.push(item);
        }
      }
      res.push_back(item);
    }
    return res;
  }
};