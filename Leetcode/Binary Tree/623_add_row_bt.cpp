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
    void addOneRowUtil(TreeNode *root, int curDepth, int val, int depth)
    {
        if (!root)
            return;
        if (curDepth == depth - 1)
        {
            TreeNode *nextLeftNode = root->left;
            TreeNode *newNode1 = new TreeNode(val);
            root->left = newNode1;
            newNode1->left = nextLeftNode;

            TreeNode *nextRightNode = root->right;
            TreeNode *newNode2 = new TreeNode(val);
            root->right = newNode2;
            newNode2->right = nextRightNode;
            return;
        }
        addOneRowUtil(root->left, curDepth + 1, val, depth);
        addOneRowUtil(root->right, curDepth + 1, val, depth);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        addOneRowUtil(root, 1, val, depth);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    int val = 1, depth = 3;
    cout << "Tree: ";
    s.inorder(root);
    cout << endl;
    cout << "Tree after adding new row: ";
    root = s.addOneRow(root, val, depth);
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/add-one-row-to-tree/

Youtube: https://www.youtube.com/watch?v=Za2OFfRLp70

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Add%20One%20Row%20to%20Tree.cpp

algorithm:

- Just go till (curdepth - 1) and add new node(val) to its left and right child

*/

/*

623. Add One Row to Tree

Given the root of a binary tree and two integers val and depth, add a row of
nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1,
create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node
with value val as the new root of the whole original tree, and the original tree is
the new root's left subtree.

Example 1:

Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]

Example 2:

Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]


*/

/*
************* Java Code **************



*/