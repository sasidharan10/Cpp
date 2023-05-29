#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
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
    ListNode *InsertEnd(ListNode *head, int n)
    {
        ListNode *temp1 = new ListNode(n);
        if (head == NULL)
        {
            head = temp1;
            return head;
        }
        ListNode *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        return head;
    }
    void print(ListNode *p)
    {

        cout << "\nList: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 9);
    s.print(head);
    s.deleteNode(head->next);
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

*/