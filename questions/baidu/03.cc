#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
  int key;
  Node *left;
  Node *right;
  Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

void val(Node *node, string &colors) {
  stack<Node *> st;
  st.push(node);
  while (!st.empty()) {
    Node *item = st.top();
    st.pop();
    // handle
    char c = colors[node->key];

    if (item->left)
      st.push(item->left);
    if (item->right)
      st.push(item->right);
  }
}

int main() {
  int n;
  cin >> n;

  string colors;
  cin >> colors;
  unordered_map<int, Node *> um;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (um.find(u) != um.end()) {
      Node *node = um[u];
      if (node->left == nullptr) {
        node->left = new Node(v);
        um[v] = node->left;
      } else if (node->right == nullptr) {
        node->right = new Node(v);
        um[v] = node->right;
      }
    } else if (um.find(v) != um.end()) {
      Node *node = um[v];
      if (node->left == nullptr) {
        node->left = new Node(u);
        um[u] = node->left;
      } else if (node->right == nullptr) {
        node->right = new Node(u);
        um[u] = node->right;
      }
    } else {
      Node *node = new Node(u);
      node->left = new Node(v);
      um[u] = node;
      um[v] = node->left;
    }
  }

  // print tree
  dfs(um[1]);
  Node *node = um[1];
  // solve
}