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

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int prefixSum = 0;
        unordered_map<int, ListNode *> mp;
        mp[0] = dummy;
        while (head)
        {
            prefixSum += head->val;
            if (mp.find(prefixSum) != mp.end())
            {
                ListNode *start = mp[prefixSum];
                ListNode *temp = start;
                int pSum = prefixSum;

                temp = temp->next;
                while (temp != head)
                {
                    pSum += temp->val;
                    mp.erase(pSum);
                    temp = temp->next;
                }
                start->next = temp->next;
            }
            else
            {
                mp[prefixSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 8);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, -3);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 1);

    // head = s.InsertEnd(head, 1);
    // head = s.InsertEnd(head, 2);
    // head = s.InsertEnd(head, -3);
    // head = s.InsertEnd(head, 3);
    // head = s.InsertEnd(head, -2);
    s.print(head);
    head = s.removeZeroSumSublists(head);
    s.print(head);
    cout << "List after removing consecutive sum 0: " << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

Youtube: https://www.youtube.com/watch?v=5UWEVMg10rY

algorithm:

- Optimal Approach:

- We take prefix sum, as we iterate the list, and store the prefix sum in the 
  map along with the node. if we encounter the same prefix sum again, then it
  means, the sum of elements is 0, between these 2 prefixes.
- hence we remove the nodes between them.

*/

/*

1171. Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences
of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]

*/