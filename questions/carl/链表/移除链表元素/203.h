#pragma once

#include "../list_node.h"

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy{0, head};
    ListNode *temp = &dummy;

    while (temp->next != nullptr) {
      if (temp->next->val == val) {
        ListNode *x = temp->next;
        temp->next = temp->next->next;
        delete x;
      } else
        temp = temp->next;
    }

    return dummy.next;
  }
};
