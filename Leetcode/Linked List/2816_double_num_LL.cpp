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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev, *current, *nextNode;
        prev = nullptr;
        current = head;
        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    // By reversing the list
    ListNode *doubleIt4(ListNode *head)
    {
        // TC: O(3n) ~ O(n)
        // SC: O(1)

        head = reverseList(head);
        int carry = 0;
        ListNode *current = head;
        ListNode *prev = nullptr;
        while (current != nullptr)
        {
            int num = current->val;
            int newNum = (num * 2) + carry;
            if (newNum > 9)
            {
                carry = 1;
                newNum = newNum % 10;
            }
            else
                carry = 0;
            current->val = newNum;
            prev = current;
            current = current->next;
        }
        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            prev->next = temp;
        }
        // print(head);
        head = reverseList(head);
        return head;
    }
    int solve(ListNode *head)
    {
        if (!head)
            return 0;
        int carry = solve(head->next);
        int newVal = head->val * 2 + carry;
        head->val = newVal % 10;
        return newVal / 10;
    }

    // Using Recursion
    ListNode *doubleIt3(ListNode *head)
    {
        int lastCarry = solve(head);
        if (lastCarry > 0)
        {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }

    // Without reversing the list
    ListNode *doubleIt2(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            int newVal = curr->val * 2;
            if (newVal < 10)
            {
                curr->val = newVal;
            }
            else if (prev != nullptr)
            {
                curr->val = newVal % 10;
                prev->val = prev->val + 1;
            }
            else
            {
                ListNode *newHead = new ListNode(1);
                newHead->next = curr;
                curr->val = newVal % 10;
                head = newHead;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }

    // We add the extra node at the start, if needed and then traverse
    ListNode *doubleIt(ListNode *head)
    {
        if (head->val >= 5)
        {
            ListNode *newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }
        ListNode *curr = head;
        while (curr != nullptr)
        {
            curr->val = (curr->val * 2) % 10;
            if (curr->next != nullptr && curr->next->val >= 5)
            {
                curr->val = curr->val + 1;
            }
            curr = curr->next;
        }
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 9);
    head = s.InsertEnd(head, 9);
    head = s.InsertEnd(head, 9);
    s.print(head);
    head = s.doubleIt(head);
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

Youtube: https://www.youtube.com/watch?v=KlB72wJDTv4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Double%20a%20Number%20Represented%20as%20a%20Linked%20List.cpp

algorithm:

- Optimal Approach:

- Self explanatory.

*/

/*

2816. Double a Number Represented as a Linked List

You are given the head of a non-empty linked list representing a non-negative
integer without leading zeroes.
Return the head of the linked list after doubling it.

Example 1:

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which
represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which
represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.

Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not
have leading zeros, except the number 0 itself.

*/

/*
************* Java Code **************

public void deleteNode(ListNode node) {
        ListNode temp = node.next;
        node.val = node.next.val;
        node.next = temp.next;
        // Java garbage collector will take care of deleting the orphaned node
    }

*/