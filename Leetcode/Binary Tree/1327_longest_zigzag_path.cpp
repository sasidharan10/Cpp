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
    int maxPath = 0;
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode *insertNode(TreeNode *root, int n)
    {
        if (root == nullptr)
        {
            TreeNode *temp = new TreeNode(n);
            return temp;
        }
        if (n <= root->val)
            root->left = insertNode(root->left, n);
        else
            root->right = insertNode(root->right, n);
        return root;
    }
    // Better
    void dfs2(TreeNode *root, int steps, bool isLeft)
    {
        if (!root)
            return;
        maxPath = max(maxPath, steps);
        if (isLeft)
        {
            dfs2(root->right, steps + 1, false);
            dfs2(root->left, 1, true);
        }
        else
        {
            dfs2(root->left, steps + 1, true);
            dfs2(root->right, 1, false);
        }
    }
    int longestZigZag2(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs2(root, 0, true);
        dfs2(root, 0, false);
        return maxPath;
    }
    // optimal (in the sense of simplicity, but both have same compplexity)
    void dfs(TreeNode *root, int lft, int rgt)
    {
        if (!root)
            return;
        maxPath = max({maxPath, lft, rgt});
        dfs(root->left, rgt + 1, 0);
        dfs(root->right, 0, lft + 1);
    }
    int longestZigZag(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, 0, 0);
        return maxPath;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->right->right = new TreeNode(1);
    cout << "Longest ZigZag Path: " << s.longestZigZag(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

Youtube:

algorithm:

*/

/*

1372. Longest ZigZag Path in a Binary Tree

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node;
otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:

Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:

Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:

Input: root = [1]
Output: 0

*/