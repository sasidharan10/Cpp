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
    void printList(ListNode *head)
    {
        cout << "\nList: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    // better - using set
    bool hasCycle(ListNode *head)
    {
        // TC: O(n)
        // SC: O(n)
        
        unordered_set<ListNode *> seen;
        ListNode *cur = head;
        while (cur)
        {
            if (seen.find(cur) != seen.end())
            {
                return true;
            }
            seen.insert(cur);
            cur = cur->next;
        }
        return false;
    }
    bool hasCycle2(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)
        
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, -4);
    s.printList(head);
    head->next->next->next = head->next;
    cout << "Has Cycle?: " << s.hasCycle(head) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/linked-list-cycle

Youtube:

algorithm:

*/

/*

141. Linked List Cycle

Given head, the head of a linked list, determine if the
linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list
that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's
next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail
connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

*/

/*

public static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }

*/