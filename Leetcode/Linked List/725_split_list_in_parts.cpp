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
        cout << "List: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // TC: O(n)
        // SC: O(n)

        vector<ListNode *> res;
        int n = 0;
        ListNode *curr = head;
        ListNode *prev;
        while (curr)
        {
            curr = curr->next;
            n++;
        }
        curr = head;
        int d = n / k;
        int extra = n % k;
        while (curr != nullptr)
        {
            res.push_back(curr);
            for (int i = 0; i < d && curr != nullptr; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            k--;
            if (extra)
            {
                prev = curr;
                curr = curr->next;
                extra--;
            }
            prev->next = nullptr; // splitting the list
        }
        while (k > 0)
        {
            res.push_back(nullptr);
            k--;
        }
        return res;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    vector<ListNode *> v;
    v = s.splitListToParts(head, 3);
    cout << "Split parts: " << endl;
    for (auto i : v)
    {
        while (i)
        {
            cout << i->val << " ";
            i = i->next;
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/split-linked-list-in-parts

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Traverse through the list and find the length of the list.
- n / k, will give the size of each part.
- N % k, will give the extra ndoes, which we can add to each parts, until it becomes 0.
- If still k > 0, then add nullptr to the array.

*/

/*

725. Split Linked List in Parts

Given the head of a singly linked list and an integer k, split the linked list into k consecutive
linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing
by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier
should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts
are a larger size than the later parts.

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50

*/

/*
************* Java Code **************

    public static ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] res = new ListNode[k];
        int s = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            s++;
        }
        curr = head;
        ListNode prev = head;
        int d = s / k;
        int extra = s % k;
        int idx = 0;
        while (curr != null) {
            res[idx] = curr;
            idx++;
            for (int i = 0; i < d && curr != null; i++) {
                prev = curr;
                curr = curr.next;
            }
            k--;
            if (extra > 0) {
                prev = curr;
                curr = curr.next;
                extra--;
            }
            prev.next = null; // splitting the list
        }
        while (k > 0) {
            res[idx] = curr;
            idx++;
            k--;
        }
        return res;
    }

*/