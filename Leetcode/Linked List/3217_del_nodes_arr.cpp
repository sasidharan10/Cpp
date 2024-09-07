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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        int n = nums.size();
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            uset.insert(nums[i]);
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        ListNode *temp = nullptr;
        while (curr != nullptr)
        {
            if (uset.find(curr->val) != uset.end())
            {
                temp = curr;
                prev->next = curr->next;
                curr = temp->next;
                temp->next = nullptr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1};
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    s.print(head);
    head = s.modifiedList(nums, head);
    cout << "\nList after deleting Middle element: ";
    s.print(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

Youtube: https://www.youtube.com/watch?v=qb7br7auuOc

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points.cpp

algorithm:

- Optimal Approach:

- Put every element from the nums[] into an unordered_set. 
- Add a dummy node, prior to the head node, to keep track of the head node.
- Now traverse though the linked list, keeping track of prev, curr node.
- Chech if current node is present in the set, if yes, then delete it.
- Else, move to next node, and update prev, curr node.

*/

/*

3217. Delete Nodes From Linked List Present in Array

You are given an array of integers nums and the head of a linked list. Return the head of the
modified linked list after removing all nodes from the linked list that have a value that exists in nums.

Example 1:
Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]

Explanation:
Remove the nodes with values 1, 2, and 3.

Example 2:
Input: nums = [1], head = [1,2,1,2,1,2]
Output: [2,2,2]

Explanation:
Remove the nodes with value 1.

Example 3:
Input: nums = [5], head = [1,2,3,4]
Output: [1,2,3,4]

Explanation:
No node has value 5.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 10^5].
1 <= Node.val <= 10^5
The input is generated such that there is at least one node in the linked list that has a value
not present in nums.

*/

/*
************* Java Code **************

    public static ListNode modifiedList(int[] nums, ListNode head) {
        int n = nums.length;
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < n; i++) {
            hs.add(nums[i]);
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        ListNode temp = null;
        while (curr != null) {
            if (hs.contains(curr.val)) {
                temp = curr;
                prev.next = curr.next;
                curr = temp.next;
                temp.next = null;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return dummy.next;
    }

*/