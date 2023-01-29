#pragma once

#include "../list_node.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *a = dummy, *b = dummy->next, *c, *d;

    while (b != nullptr && b->next != nullptr) {
      c = b->next;
      d = c->next;

      a->next = c;
      b->next = d;
      c->next = b;

      a = b;
      b = d;
    }
    ListNode *data = dummy->next;

    delete dummy;

    return data;
  }
};
