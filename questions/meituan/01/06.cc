#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
  ListNode *next;
  int val;

  ListNode(int val) : val(val), next(nullptr) {}
};

pair<ListNode *, ListNode *> reverse(ListNode *node, int k) {
  ListNode *temp = nullptr, *curr = node, *next;
  int count = 0;
  while (curr && count < k) {
    next = curr->next;
    curr->next = temp;
    temp = curr;
    curr = next;
    count++;
  }

  return {temp, curr};
}

int main() {
  int n;
  ListNode *ln = new ListNode(0);
  ListNode *head = ln;
  int length = 0;

  string nodes;
  getline(cin, nodes);
  int pos = 0, curr_pos = 0;
  while ((curr_pos = nodes.find(' ', pos)) != string::npos) {
    ln->next = new ListNode(stoi(nodes.substr(pos, curr_pos - pos)));
    pos = curr_pos + 1;
    ln = ln->next;
    length++;
  }
  ln->next = new ListNode(stoi(nodes.substr(pos)));
  length++;

  int k;
  cin >> k;
  ListNode *prev = nullptr;
  ListNode *curr = head->next;
  ListNode *result = nullptr;
  if (length < k)
    result = curr;
  else {
    for (int i = k; i <= length; i += k) {
      auto item = reverse(curr, k);
      if (result == nullptr)
        result = item.first;
      if (prev != nullptr)
        prev->next = item.first;
      prev = curr;
      curr = item.second;
    }
    if (prev != nullptr)
      prev->next = curr;
  }
  while (result) {
    cout << result->val << ' ';
    result = result->next;
  }
}
// 64 位输出请用 printf("%lld")