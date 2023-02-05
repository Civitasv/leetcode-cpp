#pragma once
#include <queue>
#include <stack>
#include <vector>

using namespace std;
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    queue<Node *> q;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        node->next = i == size - 1 ? nullptr : q.front();

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return root;
  }
};