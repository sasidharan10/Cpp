#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int sz = que.size();
            int sum = 0;
            while (sz--)
            {
                TreeNode *curr = que.front();
                que.pop();
                if (curr->left != nullptr)
                    que.push(curr->left);
                if (curr->right != nullptr)
                    que.push(curr->right);
                sum += curr->val;
            }
            pq.push(sum);
        }
        while (k != 1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);
    int k = 2;
    cout << "Result: " << s.kthLargestLevelSum(root, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

2583. Kth Largest Sum in a Binary Tree

You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.

Example 1:

Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:

Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.

Constraints:

The number of nodes in the tree is n.
2 <= n <= 10^5
1 <= Node.val <= 10^6
1 <= k <= n

*/

/*
************* Java Code **************



*/