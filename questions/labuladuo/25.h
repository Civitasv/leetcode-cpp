#pragma once
#include <utility>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Result {
  ListNode *tail;
  ListNode *head;
  ListNode *next;
};
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    Result result;
    result = reverse(head, k);
    ListNode *temp = result.head;

    while (result.next) {
      Result next = reverse(result.next, k);
      result.tail->next = next.head;
      result = next;
    }
    return temp;
  }

  Result reverse(ListNode *head, int k) {
    ListNode *pre = nullptr, *curr = head, *next = nullptr;
    ListNode *temp = head;
    int count = 0;
    while (temp != nullptr) {
      temp = temp->next;
      count++;
    }
    if (count < k)
      return {nullptr, head, nullptr};

    while (curr && k != 0) {
      next = curr->next;
      curr->next = pre;
      pre = curr;
      curr = next;
      k--;
    }
    return {head, pre, curr};
  }
};