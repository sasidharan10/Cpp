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
    int maxDiff;
    void solve2(TreeNode *root, TreeNode *ancestor)
    {
        if (!root)
            return;
        maxDiff = max(maxDiff, abs(root->val - ancestor->val));
        solve2(root->left, ancestor);
        solve2(root->right, ancestor);
    }
    void maxAncestorDiffUtil(TreeNode *root)
    {
        // TC: O(n^2)
        // SC: O(1) + O(height)

        if (!root)
            return;
        solve2(root->left, root);
        solve2(root->right, root);
        maxAncestorDiffUtil(root->left);
        maxAncestorDiffUtil(root->right);
    }
    int solve(TreeNode *root, int maxi, int mini)
    {
        // TC: O(n)
        // SC: O(1) + O(height)

        if (!root)
            return (maxi - mini);
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        int lt = solve(root->left, maxi, mini);
        int rt = solve(root->right, maxi, mini);
        return max(lt, rt);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        maxDiff = -1;
        // maxAncestorDiffUtil(root);
        // return maxDiff;
        return solve(root, INT_MIN, INT_MAX);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    cout << "Maximum Difference Between Node and Ancestor: ";
    cout << s.maxAncestorDiff(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

Youtube: https://www.youtube.com/watch?v=cvekQzmBdcs

algorithm:

*/

/*

1026. Maximum Difference Between Node and Ancestor

Given the root of a binary tree, find the maximum value v for which there
exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or
any child of a is an ancestor of b.

Example 1:

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:

Input: root = [1,null,2,null,0,3]
Output: 3

*/