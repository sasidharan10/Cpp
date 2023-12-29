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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *oddPointer = head, *current = head;
        ListNode *evenPointer = head->next, *evenHead = head->next;
        current = evenHead->next;
        bool flag = true;
        while (current)
        {
            if (flag)
            {
                oddPointer->next = current;
                oddPointer = oddPointer->next;
                flag = false;
            }
            else
            {
                evenPointer->next = current;
                evenPointer = evenPointer->next;
                flag = true;
            }
            current = current->next;
        }
        oddPointer->next = evenHead;
        evenPointer->next = nullptr;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 7);
    s.print(head);
    head = s.oddEvenList(head);
    cout << "\nOdd-Even List: ";
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/odd-even-linked-list

Youtube:

algorithm:

- We keep 2 pointers, where we append the odd, even nodes to them.
- use flag variable, to denote if current node is odd or even.
- once the traversal is completed, we append the even list's head to the 
  end of odd list's node. and also assign even node->next = NULL, to break
  the link.
  
*/

/*

328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd 
indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

*/