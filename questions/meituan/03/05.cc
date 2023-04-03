#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int count = 0;

struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

pair<int, int> helper(string colors, TreeNode *node) {
  if (node == nullptr) {
    return {0, 0};
  }

  pair<int, int> result{0, 0};
  auto left = helper(colors, node->left);
  auto right = helper(colors, node->right);
  result.first += left.first;
  result.first += right.first;
  result.second += left.second;
  result.second += right.second;

  if (result.first == result.second) {
    count++;
  }

  if (colors[node->val - 1] == 'R')
    result.first++;
  else
    result.second++;

  return result;
}

int main() {
  int n;
  cin >> n;
  string colors;
  cin >> colors;
  vector<int> nodes(n - 1, 0);
  for (int i = 0; i < n - 1; i++) {
    cin >> nodes[i];
  }

  // build tree
  TreeNode *root = new TreeNode(1);
  queue<TreeNode *> q;
  q.push(root);

  for (int i = 0; i < nodes.size(); i += 2) {
    TreeNode *curr = q.front();
    q.pop();
    if (i < nodes.size()) {
      int a = nodes[i];
      curr->left = new TreeNode(a);
      q.push(curr->left);
    }
    if (i + 1 < nodes.size()) {
      int b = nodes[i + 1];
      curr->right = new TreeNode(b);
      q.push(curr->right);
    }
  }

  // Solve
  helper(colors, root);
  cout << count << '\n';
}