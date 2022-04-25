#include <iostream>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *cur = head, *next = head->next;
        cur->next = nullptr;
        while (cur != nullptr && next != nullptr)
        {
            ListNode *next2 = next->next;
            next->next = cur;
            cur = next;
            next = next2;
        }

        return cur;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    Solution s;
    ListNode *node = s.reverseList(l1);
    while (node != nullptr)
    {
        cout << node->val << endl;
        node = node->next;
    }
}