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
        cout << "List: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    // brute - creating new nodes, and assigning the sums between the 0's
    ListNode *mergeNodes3(ListNode *head)
    {
        // TC: O(n)
        // SC: O(n)

        int sum = 0;
        ListNode *newhead = new ListNode(0);
        ListNode *newList = newhead;
        head = head->next;
        while (head != nullptr)
        {
            if (head->val == 0)
            {

                ListNode *newNode = new ListNode(sum);
                newList->next = newNode;
                newList = newList->next;
                sum = 0;
            }
            sum += head->val;
            head = head->next;
        }
        return newhead->next;
    }

    // Better - Using recursion
    ListNode* mergeNodes2(ListNode* head) {
        head = head->next;
        if(head == NULL) {
            return head;
        }

        ListNode* temp = head;
        int sum = 0;
        while(temp != NULL && temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp); //Recursion leap of faith
        return head;
    }

    // Optimal - using in-place algorithm (using existing nodes)
    ListNode *mergeNodes(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)

        int sum = 0;
        ListNode *newhead = head;
        ListNode *newList = head;
        ListNode *prevNode = nullptr;
        head = head->next;
        while (head != nullptr)
        {
            if (head->val == 0)
            {
                // unlinking other nodes from our nodes
                if (prevNode != nullptr)
                    prevNode->next = nullptr;
                newList->next = head;
                head->val = sum;            // assigning the sum to the current node
                newList = newList->next;    // moving newlist to point the current node
                sum = 0;                    // sum becomes 0 again
            }
            else
            {
                sum += head->val;
            }
            prevNode = head;
            head = head->next;
        }
        return newhead->next;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 0);
    s.print(head);
    head = s.mergeNodes(head);
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-nodes-in-between-zeros

Youtube: https://www.youtube.com/watch?v=GyoRAaVCOKs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Merge%20Nodes%20in%20Between%20Zeros.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

2181. Merge Nodes in Between Zeros

You are given the head of a linked list, which contains a series of integers separated 
by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single 
node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Example 1:

Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:

Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 
Constraints:

The number of nodes in the list is in the range [3, 2 * 10^5].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.

*/

/*
************* Java Code **************

public ListNode mergeNodes(ListNode head) {
        int sum = 0;
        ListNode newhead = head;
        ListNode newList = head;
        ListNode prevNode = null;
        head = head.next;
        while (head != null) {
            if (head.val == 0) {
                if (prevNode != null)
                    prevNode.next = null;
                newList.next = head;
                head.val = sum;
                newList = newList.next;
                sum = 0;
            } else {
                sum += head.val;
            }
            prevNode = head;
            head = head.next;
        }
        return newhead.next;
    }

*/