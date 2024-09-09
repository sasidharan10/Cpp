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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        // TC: O(l) where l = total nodes
        // SC: O(n*m)
        
        vector<vector<int>> res(m, vector<int>(n, -1));
        int direction = 0;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        while (top <= bottom && left <= right && head != nullptr)
        {
            if (direction == 0)
            {
                for (int i = left; i <= right && head != nullptr; i++)
                {
                    res[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            else if (direction == 1)
            {
                for (int i = top; i <= bottom && head != nullptr; i++)
                {
                    res[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            else if (direction == 2)
            {
                for (int i = right; i >= left && head != nullptr; i--)
                {
                    res[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            else
            {
                for (int i = bottom; i >= top && head != nullptr; i--)
                {
                    res[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return res;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 8);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 9);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 0);
    int m = 3, n = 5;
    s.printList(head);
    vector<vector<int>> ans = s.spiralMatrix(m, n, head);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/spiral-matrix-iv

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

2326. Spiral Matrix IV

You are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral
order (clockwise), starting from the top-left of the matrix. If there are remaining empty
spaces, fill them with -1.

Return the generated matrix.

Example 1:

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.

Constraints:

1 <= m, n <= 10^5
1 <= m * n <= 10^5
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000

*/

/*
************* Java Code **************

    public static int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(res[i], -1);
        }
        int direction = 0;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        while (top <= bottom && left <= right && head != null) {
            if (direction == 0) {
                for (int i = left; i <= right && head != null; i++) {
                    res[top][i] = head.val;
                    head = head.next;
                }
                top++;
            }

            else if (direction == 1) {
                for (int i = top; i <= bottom && head != null; i++) {
                    res[i][right] = head.val;
                    head = head.next;
                }
                right--;
            } else if (direction == 2) {
                for (int i = right; i >= left && head != null; i--) {
                    res[bottom][i] = head.val;
                    head = head.next;
                }
                bottom--;
            } else {
                for (int i = bottom; i >= top && head != null; i--) {
                    res[i][left] = head.val;
                    head = head.next;
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return res;
    }

*/