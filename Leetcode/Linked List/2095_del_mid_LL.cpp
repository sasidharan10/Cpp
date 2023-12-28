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
    void print(ListNode *p)
    {

        cout << "\nList: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)

        if (!head->next)
            return nullptr;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 6);
    s.print(head);
    head = s.deleteMiddle(head);
    cout << "\nList after deleting Middle element: ";
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

Youtube:

algorithm:

- use floyd cycle detection, and iterate the list.
- the slow pointer will end at the middle node.
- have a prev node, to keep track of slow's previous node.
- then unlink the middle node, using prev node.

*/

/*

2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and
return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from
the start using 0-based indexing, where ⌊x⌋ denotes the largest
integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Example 1:

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.

Example 2:

Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Example 3:

Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.

*/