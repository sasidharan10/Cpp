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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = nullptr;
        while (current)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        return head;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        int carry = 0;
        while (l1 && l2)
        {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l2 = l2->next;
            l1 = l1->next;
        }
        while (l1)
        {
            int value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l2 = l2->next;
        }
        if (carry)
            l3->next = new ListNode(carry);
        return reverseList(head->next);
    }
};
int main()
{
    Solution s;
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    l1 = s.InsertEnd(l1, 7);
    l1 = s.InsertEnd(l1, 2);
    l1 = s.InsertEnd(l1, 4);
    l1 = s.InsertEnd(l1, 3);
    s.printList(l1);
    l2 = s.InsertEnd(l2, 5);
    l2 = s.InsertEnd(l2, 6);
    l2 = s.InsertEnd(l2, 4);
    s.printList(l2);
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    s.printList(l3);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/add-two-numbers-ii/

*/