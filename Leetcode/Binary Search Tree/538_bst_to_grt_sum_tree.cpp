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
    void solve(TreeNode *root, int &sum)
    {
        if (root == nullptr)
            return;
        solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve(root->left, sum);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->left->right->right = new TreeNode(3);
    cout << "\nTree: ";
    s.inorder(root);
    root = s.bstToGst(root);
    cout << "\nTree After Modification: ";
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/convert-bst-to-greater-tree/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Since its a BST, all right nodes have values greater than its current node.
- Hence we have to take the sum of curr->val + sum(all right nodes) and assign
  it to the current tree.
- So we do a reverse Inorder traversal (right - root - left), and assign the sum to curr->val.

*/

/*

538. Convert BST to Greater Tree

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every 
key of the original BST is changed to the original key plus the sum of all keys greater 
than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 
Constraints:

The number of nodes in the tree is in the range [0, 104].
-104 <= Node.val <= 104
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.

*/

/*
************* Java Code **************

private static int sum;

    public static void solve(TreeNode root) {
        if (root == null)
            return;
        solve(root.right);
        sum += root.val;
        root.val = sum;
        solve(root.left);
    }

    public static TreeNode bstToGst(TreeNode root) {
        sum = 0;
        solve(root);
        return root;
    }

*/