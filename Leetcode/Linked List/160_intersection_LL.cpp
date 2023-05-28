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
    void printList(ListNode *head)
    {
        cout << "List: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            if (!a)
                a = headB;
            else
                a = a->next;
            if (!b)
                b = headA;
            else
                b = b->next;
        }
        return a;
    }
};
int main()
{
    Solution s;
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    l1 = s.InsertEnd(l1, 1);
    l1 = s.InsertEnd(l1, 2);
    l1 = s.InsertEnd(l1, 3);
    l1 = s.InsertEnd(l1, 4);
    l1 = s.InsertEnd(l1, 5);
    l1 = s.InsertEnd(l1, 6);
    l1 = s.InsertEnd(l1, 7);

    l2 = s.InsertEnd(l2, 10);
    l2 = s.InsertEnd(l2, 20);
    l2->next->next = l1->next->next->next->next;
    s.printList(l1);
    s.printList(l2);
    cout << "Intersection: " << s.getIntersectionNode(l1, l2)->val << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

*/