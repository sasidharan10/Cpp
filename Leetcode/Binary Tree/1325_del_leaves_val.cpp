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

    // Brute force
    bool delSubtree(TreeNode *root, int target)
    {
        if (root == nullptr)
            return true;
        if (root->val != target)
            return false;
        bool lt = delSubtree(root->left, target);
        bool rt = delSubtree(root->right, target);
        return lt & rt;
    }
    void solve(TreeNode *root, TreeNode *parent, bool isLeft, int target)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && root->val == target)
        {
            if (isLeft)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            return;
        }
        else if (root->val == target)
        {
            if (delSubtree(root, target))
            {
                if (isLeft)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
                return;
            }
        }
        solve(root->left, root, true, target);
        solve(root->right, root, false, target);
    }
    TreeNode *removeLeafNodes2(TreeNode *root, int target)
    {
        solve(root->left, root, true, target);
        solve(root->right, root, false, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target)
            return nullptr;
        return root;
    }

    // Optimal
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target)
            return nullptr;
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    int target = 2;
    // root = new TreeNode(1);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(1);
    // int target = 1;
    cout << "\nTree: ";
    s.inorder(root);
    root = s.removeLeafNodes(root, target);
    cout << "\nResult: ";
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/delete-leaves-with-a-given-value/

Youtube: https://www.youtube.com/watch?v=OzueBIOLJ44

Code Link:

algorithm:

-

*/

/*

1325. Delete Leaves With a Given Value

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a
leaf node and has the value target, it should also be deleted (you need to continue doing
that until you cannot).

Example 1:

Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left).
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

Example 2:

Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]

Example 3:

Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

*/

/*
************* Java Code **************

public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root == null) {
            return null;
        }

        root.left  = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);

        if(root.left == null && root.right == null && root.val == target)
            return null;

        return root;
    }

*/