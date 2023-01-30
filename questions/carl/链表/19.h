#pragma once

#include "list_node.h"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // slow and fast pointer
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode *slow = head, *fast = head;

    for (int i = 0; i < n; i++)
      fast = fast->next;

    if (fast == nullptr) {
      return head->next;
    }

    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
  }
};
