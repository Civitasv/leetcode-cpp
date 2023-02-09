#pragma once
#include <unordered_map>

using namespace std;

struct DListNode {
  int key;
  int value;
  DListNode *next;
  DListNode *prev;
  DListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
  DListNode(int x) : key(x), value(0), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
  unordered_map<int, DListNode *> map;
  DListNode *head;
  DListNode *tail;
  int capacity;
  int size;

private:
  void AddToHead(DListNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }
  void RemoveNode(DListNode *node) {
    DListNode *prev = node->prev;
    DListNode *next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  DListNode *RemoveTail() {
    DListNode *node = tail->prev;
    RemoveNode(node);
    return node;
  }

  void MoveItemHead(DListNode *node) {
    RemoveNode(node);
    AddToHead(node);
  }

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new DListNode();
    tail = new DListNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (map.find(key) == map.end())
      return -1;
    else {
      DListNode *node = map[key];
      MoveItemHead(node);
      return node->value;
    }
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      DListNode *node = map[key];
      node->value = value;
      MoveItemHead(node);
      return;
    }
    DListNode *node = new DListNode(key);
    node->value = value;
    AddToHead(node);
    map[key] = node;
    size++;
    if (size > capacity) {
      DListNode *rm = RemoveTail();
      map.erase(rm->key);
      delete rm;
      size--;
    }
  }
};