// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/二叉树/102.h"

using namespace std;

int main() {
  Solution s;
  TreeNode node(3);
  TreeNode node2(9);
  TreeNode node3(20);
  TreeNode node4(15);
  TreeNode node5(7);

  node.left = &node2;
  node.right = &node3;
  node3.left = &node4;
  node3.right = &node5;

  auto res = s.levelOrder(&node);

  for (auto &item : res) {
    for (auto &i : item)
      cout << i << ' ';
    cout << '\n';
  }
}
