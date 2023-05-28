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
    void splitList(ListNode **left, ListNode **right, ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *left = head;
        *right = slow->next;
        slow->next = nullptr;
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *res = nullptr;
        if (!left)
            return right;
        if (!right)
            return left;
        if (left->val <= right->val)
        {
            res = left;
            res->next = merge(left->next, right);
        }
        else
        {
            res = right;
            res->next = merge(left, right->next);
        }
        return res;
    }
    void mergeSort(ListNode **head)
    {
        ListNode *current = *head;
        ListNode *left;
        ListNode *right;
        if (!current || !current->next)
            return;
        splitList(&left, &right, current);
        mergeSort(&left);
        mergeSort(&right);
        *head = merge(left, right);
    }
    ListNode *sortList(ListNode *head)
    {
        mergeSort(&head);
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    head = s.sortList(head);
    s.printList(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-list/description/

*/