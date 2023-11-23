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
        cout << root->val << " ";
        inorder(root->left);
        inorder(root->right);
    }
    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val == subRoot->val)
        {
            return isSame(root->left, subRoot->left) & isSame(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
            return true;
        if (!root)
            return false;
        if (isSame(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(0);
    // cout << "\nTree: ";
    // s.inorder(root);
    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    // cout << "\nSub Tree: ";
    // s.inorder(subRoot);
    cout << "\nIs given Subtree present in Another Tree: " << s.isSubtree(root, subRoot) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/subtree-of-another-tree/

Youtube:

algorithm:

*/

/*

572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this
node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

*/