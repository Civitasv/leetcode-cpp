#pragma once
#include <memory>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
private:
  ListNode *head;
  int len;

public:
  MyLinkedList() : head(nullptr), len(0) {}

  ~MyLinkedList() {
    for (int i = 0; i < len; i++)
      deleteAtIndex(i);
  }

  int get(int index) {
    if (index >= len)
      return -1;

    ListNode *node = head;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }

    return node->val;
  }

  void addAtHead(int val) {
    ListNode *node = new ListNode(val, head);
    if (head != nullptr) {
      node->next = head;
    }
    head = node;
    len++;
  }

  void addAtTail(int val) {
    ListNode *node = new ListNode(val);
    if (head == nullptr)
      head = node;
    else {
      ListNode *temp = head;
      for (int i = 0; i < len - 1; i++) {
        temp = temp->next;
      }
      temp->next = node;
    }
    len++;
  }

  void addAtIndex(int index, int val) {
    if (index <= 0) {
      addAtHead(val);
    } else if (index == len) {
      addAtTail(val);
    } else if (index > 0 && index < len) {
      ListNode *node = head;
      for (int i = 0; i < index - 1; i++) {
        node = node->next;
      }

      ListNode *temp = node->next;
      node->next = new ListNode(val, temp);
      len++;
    }
  }

  void deleteAtIndex(int index) {
    if (index == 0) {
      len--;
      ListNode *temp = head;
      head = head->next;
      delete temp;
    } else if (index > 0 && index < len) {
      len--;
      ListNode *node = head;
      for (int i = 0; i < index - 1; i++) {
        node = node->next;
      }

      ListNode *temp = node->next;
      node->next = node->next->next;
      delete temp;
    }
  }
};
