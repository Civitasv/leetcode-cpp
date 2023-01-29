// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/链表/移除链表元素/24.h"

using namespace std;

int main() {
  Solution s;
  ListNode *head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

  auto res = s.swapPairs(head);

  while (res != nullptr) {
    cout << res->val << " ";
    res = res->next;
  }
}
