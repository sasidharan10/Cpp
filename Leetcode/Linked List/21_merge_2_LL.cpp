#include <bits/stdc++.h>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Dummy node to simplify edge cases
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        // If either list is empty, return the other
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;  // attach smaller node
                list1 = list1->next; // move list1 pointer
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next; // advance merged list pointer
        }

        // Attach remaining nodes (at most one list is non-empty)
        if (list1 != nullptr)
            curr->next = list1;
        else
            curr->next = list2;

        return dummy->next; // skip dummy node
    }
};
int main()
{
    Solution s;
    ListNode *head1 = NULL;
    head1 = s.InsertEnd(head1, 1);
    head1 = s.InsertEnd(head1, 2);
    head1 = s.InsertEnd(head1, 4);
    ListNode *head2 = NULL;
    head2 = s.InsertEnd(head2, 1);
    head2 = s.InsertEnd(head2, 3);
    head2 = s.InsertEnd(head2, 4);
    head2 = s.InsertEnd(head2, 5);
    s.printList(head1);
    s.printList(head2);
    head1 = s.mergeTwoLists(head1, head2);
    s.printList(head2);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-two-sorted-lists/

Youtube: https://www.youtube.com/watch?v=XIdigk956u0

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

/*
************* Java Code **************

    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        if (list1 != null)
            curr.next = list1;
        else
            curr.next = list2;

        return dummy.next;
    }

*/