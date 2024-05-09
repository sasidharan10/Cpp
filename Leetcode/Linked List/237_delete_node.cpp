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
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = temp->next;
        delete temp;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 9);
    s.print(head);
    s.deleteNode(head->next);
    s.print(head);
    return 0;
}


/*

link: 

leetcode: https://leetcode.com/problems/delete-node-in-a-linked-list/

Youtube: 

Code Link: 

algorithm: 

- Optimal Approach:

- Its given that the del node will not be the last node.
- Given list [4, 5, 1, 3], del = 5
- We assign del = del.next => [4, 1, 1, 3]
- Now we remove the del.next node, and link the del to del.next.next.

*/

/*

237. Delete Node in a Linked List

There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node 
is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to 
be given node. node should not be the last node of the list and should 
be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.
 
Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should 
become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should 
become 4 -> 5 -> 9 after calling your function.

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