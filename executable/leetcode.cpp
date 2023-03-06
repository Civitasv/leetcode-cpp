// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <string>
#include <vector>

#include "questions/a_unique_ptr.h"

// void Helper(TreeNode *node) {
//   if (node == nullptr) {
//     return;
//   }
//   cout << node->val << '\n';
//
//   cout << "left:: ";
//   Helper(node->left);
//   cout << "right:: ";
//   Helper(node->right);
// }

int main() {
  UniquePtr<std::string> unique_ptr(new std::string("Hello"));
  std::cout << unique_ptr->c_str() << '\n';
  UniquePtr<std::string> unique_ptr2(std::move(unique_ptr));
  UniquePtr<std::string> unique_ptr3(new std::string("ANOTHER"));
  unique_ptr3 = std::move(unique_ptr2);
  std::cout << unique_ptr3->c_str() << '\n';
}
