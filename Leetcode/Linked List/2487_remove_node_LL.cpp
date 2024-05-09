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

    // using stack and traversing in reverse order.
    ListNode *removeNodes4(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *current = head;
        while (current != nullptr)
        {
            st.push(current);
            current = current->next;
        }
        int maxi = st.top()->val;
        ListNode *resulthead = st.top();
        ListNode *newList = st.top();
        st.pop();
        while (!st.empty())
        {
            if (st.top()->val >= maxi)
            {
                maxi = st.top()->val;
                ListNode *temp = st.top();
                temp->next = newList;
                newList = temp;
                resulthead = newList;
            }
            st.pop();
        }
        return resulthead;
    }

    // using Recursion
    ListNode *solve(ListNode *current)
    {
        if (!current)
            return nullptr;
        ListNode *prev = solve(current->next);
        if (!prev || current->val >= prev->val)
        {
            current->next = prev;
            return current;
        }
        else
            return prev;
    }

    ListNode *removeNodes3(ListNode *head)
    {
        head = solve(head);
    }

    // By reversing the list
    ListNode *removeNodes2(ListNode *head)
    {
        // TC: O(3n)
        // SC: O(1)

        head = reverseList(head);
        print(head);
        ListNode *current = head;
        ListNode *prev = nullptr;
        int maxi = INT_MIN;
        while (current != nullptr)
        {
            if (prev != nullptr && current->val < maxi)
            {
                prev->next = current->next;
                ListNode *temp = current;
                current = current->next;
                temp->next = nullptr;
                delete temp;
            }
            else
            {
                maxi = current->val;
                prev = current;
                current = current->next;
            }
        }
        return reverseList(head);
    }

    // Using monotonic stack
    ListNode *removeNodes(ListNode *head)
    {
        // TC: O(n)
        // SC: O(n)

        stack<ListNode *> st;
        st.push(head);
        head = head->next;
        while (head != nullptr)
        {
            int current = head->val;
            while (!st.empty() && current > st.top()->val)
            {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode *newList = st.top();
        newList->next = nullptr;
        st.pop();
        while (!st.empty())
        {
            ListNode *temp = st.top();
            temp->next = newList;
            newList = temp;
            st.pop();
        }
        return newList;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 13);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 8);
    s.print(head);
    head = s.removeNodes(head);
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-nodes-from-linked-list/

Youtube: https://www.youtube.com/watch?v=RTVG66xulcA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Remove%20Nodes%20From%20Linked%20List.cpp

algorithm:


- Approach:

- If we traverse the list in reverse order, it is easy to solve this.
- We take the first element, then we check if next element is greater or equal to curr.
- If yes, we take that element and check it with next element.
- Traversing in reverse order can be done by 3 methods, Using stack, recursion or just 
  reverse the list and traverse. Monotonic can also be used, explained below.

- Monotonic stack:
- The goal is to make the list in decreasing order, by removing any number of elements.
- We push the first element in the stack.
- If any greater element is found, we add that to the stack, hence maintaining
  a decreasing order in the stack.
- Once traversal is complete, we have the list in the stack, hence we pop every node
  and the resultant list. The nodes will be in reverse order in the stack, hence
  we have to create the list accordingly.

*/

/*

2487. Remove Nodes From Linked List

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:

Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

*/

/*
************* Java Code **************

public static ListNode removeNodes(ListNode head) {
        Stack<ListNode> st = new Stack<>();
        ListNode current = head;
        while (current != null) {
            st.push(current);
            current = current.next;
        }
        int maxi = st.peek().val;
        ListNode resulthead = st.peek();
        ListNode newList = st.peek();
        st.pop();
        while (!st.isEmpty()) {
            if (st.peek().val >= maxi) {
                maxi = st.peek().val;
                ListNode temp = st.peek();
                temp.next = newList;
                newList = temp;
                resulthead = newList;
            }
            st.pop();
        }
        return resulthead;
    }

*/