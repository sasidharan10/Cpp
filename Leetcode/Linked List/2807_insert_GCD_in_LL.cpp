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
    int findGCD(int a, int b)
    {
        while (b != 0)
        {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        // TC: O(n)
        // SC: O(n/2)
        
        if (head->next == nullptr)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        while (second != nullptr)
        {
            int temp = findGCD(first->val, second->val);
            ListNode *middle = new ListNode(temp);
            first->next = middle;
            middle->next = second;
            first = second;
            second = second->next;
        }
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 18);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 10);
    head = s.InsertEnd(head, 3);
    s.printList(head);
    head = s.insertGreatestCommonDivisors(head);
    cout << "Result: " << endl;
    s.printList(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Keep 2 pointers to keep track of the pairs in the list.
- Find the gcd of the pair, and just insert it in the middle.

*/

/*

2807. Insert Greatest Common Divisors in Linked List

Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common
divisor of them.
Return the linked list after insertion.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:

Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the
linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

Example 2:

Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the
linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.

Constraints:

The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000

*/

/*
************* Java Code **************

    public static int findGCD(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head.next == null)
            return head;
        ListNode first = head;
        ListNode second = head.next;
        while (second != null) {
            int temp = findGCD(first.val, second.val);
            ListNode middle = new ListNode(temp);
            first.next = middle;
            middle.next = second;
            first = second;
            second = second.next;
        }
        return head;
    }

*/