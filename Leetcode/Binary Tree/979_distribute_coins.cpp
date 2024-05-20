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
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root == nullptr)
            return;
        parent[root->left] = root;
        parent[root->right] = root;
        findParent(root->left, parent);
        findParent(root->right, parent);
    }
    int cnt;
    unordered_map<TreeNode *, TreeNode *> parent;
    void solve(TreeNode *root, unordered_map<TreeNode *, bool> vis)
    {
        if (root->val >= 1)
            return;
        TreeNode *original = root;
        queue<TreeNode *> que;
        que.push(root);
        vis[root] = true;
        int dis = 0;
        while (!que.empty())
        {
            TreeNode *maxNode = nullptr;
            int maxi = 1;
            int sz = que.size();
            while (sz--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->val > maxi)
                {
                    maxi = node->val;
                    maxNode = node;
                }
                if (parent[node] != nullptr && !vis[parent[node]])
                {
                    que.push(parent[node]);
                    vis[parent[node]] = true;
                }
                if (node->left != nullptr && !vis[node->left])
                {
                    que.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right != nullptr && !vis[node->right])
                {
                    que.push(node->right);
                    vis[node->right] = true;
                }
            }
            if (maxNode != nullptr)
            {
                cnt += dis;
                maxNode->val = maxNode->val - 1;
                original->val = 1;
                return;
            }
            dis++;
        }
    }
    void helper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        unordered_map<TreeNode *, bool> vis;
        solve(root, vis);
        helper(root->left);
        helper(root->right);
    }
    int distributeCoins(TreeNode *root)
    {
        findParent(root, parent);
        parent[root] = nullptr;
        cnt = 0;
        helper(root);
        return cnt;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->left->left->left = new TreeNode(1);

    // root = new TreeNode(0);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(0);
    cout << "\nTree: ";
    s.inorder(root);
    cout << "\nResult: " << s.distributeCoins(root);
    cout << "\nTree: ";
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/distribute-coins-in-binary-tree/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

979. Distribute Coins in Binary Tree

You are given the root of a binary tree with n nodes where each node in the
tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node
to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:

Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one
coin to its right child.

Example 2:

Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].
Then, we move one coin from the root of the tree to the right child.

*/

/*
************* Java Code **************



*/