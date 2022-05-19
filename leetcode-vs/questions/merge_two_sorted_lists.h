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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *res = nullptr;
        ListNode *p = nullptr;
        while (list1 != nullptr || list2 != nullptr)
        {
            ListNode *node;
            if (list1 == nullptr)
            {
                node = new ListNode(list2->val);
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                node = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                int val1 = list1->val, val2 = list2->val;
                node = new ListNode(val1 > val2 ? val2 : val1);
                if (val1 > val2)
                    list2 = list2->next;
                else
                    list1 = list1->next;
            }
            if (p != nullptr)
                p->next = node;
            else
                p = res = node;
            p = node;
        }
        return res;
    }
};

