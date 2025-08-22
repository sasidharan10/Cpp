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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // TC: O(n)
        // SC: O(1)

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
    ListNode *removeNthFromEnd2(ListNode *head, int n)
    {
        // TC: O(2n)
        // SC: O(1)

        int s = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            s++;
        }
        int k = s - n;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        temp = dummy;
        for (int i = 0; i < k; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return dummy->next;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    head = s.removeNthFromEnd(head, 3);
    s.printList(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

*/

/*

19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end 
of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

*/

/*

public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy;
        ListNode slow = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }

*/