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
    vector<int> nodesBetweenCriticalPoints2(ListNode *head)
    {
        // TC: O(n) + O(m) where m = no of critical points.
        // SC: O(m)

        ListNode *prev = head;
        ListNode *curr = head->next;
        vector<int> criticalPoints;
        int index = 2;
        while (curr != nullptr)
        {
            if (curr->next != nullptr)
            {
                if ((prev->val > curr->val) && (curr->next->val > curr->val))
                    criticalPoints.push_back(index);
                else if ((prev->val < curr->val) && (curr->next->val < curr->val))
                    criticalPoints.push_back(index);
            }
            index++;
            prev = curr;
            curr = curr->next;
        }
        int n = criticalPoints.size();

        if (n <= 1)
            return {-1, -1};

        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            minDiff = min(minDiff, criticalPoints[i] - criticalPoints[i - 1]);
        }
        int maxDiff = criticalPoints[n - 1] - criticalPoints[0];
        return {minDiff, maxDiff};
    }

    // Optimal - Without storing critical points
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        // TC: O(n)
        // SC: O(1)

        ListNode *prev = head;
        ListNode *curr = head->next;
        int minDiff = INT_MAX;
        int firstIndex = 0;
        int prevIndex = 0;
        int index = 2;
        while (curr != nullptr)
        {
            if (curr->next != nullptr)
            {
                if ((prev->val > curr->val && curr->next->val > curr->val) || (prev->val < curr->val && curr->next->val < curr->val))
                {
                    if (firstIndex == 0)
                    {
                        firstIndex = index;
                    }
                    else
                    {
                        minDiff = min(minDiff, index - prevIndex);
                    }
                    prevIndex = index;
                }
            }
            index++;
            prev = curr;
            curr = curr->next;
        }

        if (minDiff == INT_MAX)
            return {-1, -1};
        return {minDiff, prevIndex - firstIndex};
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);

    // head = s.InsertEnd(head, 3);
    // head = s.InsertEnd(head, 1);
    // head = s.InsertEnd(head, 2);
    // head = s.InsertEnd(head, 1);
    s.print(head);
    vector<int> ans = s.nodesBetweenCriticalPoints(head);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

Youtube: https://www.youtube.com/watch?v=RPxCrG3F8CE

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Linked%20List/Find%20the%20Minimum%20and%20Maximum%20Number%20of%20Nodes%20Between%20Critical%20Points.cpp

algorithm:

- Brute force

- Storing all critical points in an array, and then finding the minDiff and maxDiff.
- MinDiff can be found by finding the minimum difference between any to aadjacent critical points.
- MaxDiff can be found by taking the difference of first and last critical point.

- Optimal Approach:

- Instead of storing the critical points, we use 2 points, to store the first CP and previous CP.
- Initially minDiff == INT_MAX. If after looping through the listNode, still (minDiff == INT_MAX),
  then we haven't found 2 critical points in the list, hence we return {-1, -1}.
- While updating prevIndex, we try to find the minDiff between prevIndex and current Index.
- For finding maxDiff, we use FirstIndex and prevIndex.

*/

/*

2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous
node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous
node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where
minDistance is the minimum distance between any two distinct critical points and maxDistance
is the maximum distance between any two distinct critical points. If there are fewer than two
critical points, return [-1, -1].

Example 1:

Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

Example 2:

Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

Example 3:

Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.

Constraints:

The number of nodes in the list is in the range [2, 10^5].
1 <= Node.val <= 10^5

*/

/*
************* Java Code **************

public static int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = head;
        ListNode curr = head.next;
        int minDiff = Integer.MAX_VALUE;
        int firstIndex = 0;
        int prevIndex = 0;
        int index = 2;
        while (curr != null) {
            if (curr.next != null) {
                if ((prev.val > curr.val && curr.next.val > curr.val)
                        || (prev.val < curr.val && curr.next.val < curr.val)) {
                    if (firstIndex == 0) {
                        firstIndex = index;
                    } else {
                        minDiff = Math.min(minDiff, index - prevIndex);
                    }
                    prevIndex = index;
                }
            }
            index++;
            prev = curr;
            curr = curr.next;
        }

        if (minDiff == Integer.MAX_VALUE)
            return new int[] { -1, -1 };
        return new int[] { minDiff, prevIndex - firstIndex };
    }

*/