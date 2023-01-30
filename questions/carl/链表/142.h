#pragma once

#include "list_node.h"

// NOTE: f = 2s
// 若，s = a + y
// 则，f = a + y + nb
// 所以，f = nb + s
// 所以，s = nb
// 当 slow 走 a + nb，一定处于环入口
// 所以, s 只要再走 a，就可以到达环入口
// 且，head 只要再走 a，就可以到达环入口
// 所以，二者相等时，就走到了环入口
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (true) {
      if (fast == nullptr || fast->next == nullptr)
        return nullptr;
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        break;
    }

    ListNode *node = head;

    while (node != slow) {
      node = node->next;
      slow = slow->next;
    }

    return slow;
  }
};
