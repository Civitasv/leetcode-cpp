#pragma once

#include "../list_node.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    // ListNode *curr = nullptr;
    // ListNode *next = head;
    // ListNode *nnext;
    //
    // while (next != nullptr) {
    //   nnext = next->next;
    //   next->next = curr;
    //
    //   curr = next;
    //   next = nnext;
    // }
    //
    // return curr;

    return reverse(nullptr, head);
  }

  ListNode *reverse(ListNode *curr, ListNode *next) {
    if (next == nullptr)
      return curr;

    ListNode *nnext = next->next;
    next->next = curr;

    return reverse(next, nnext);
  }
};
