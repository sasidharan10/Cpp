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
    bool evaluateTree(TreeNode *root)
    {
        if (!root)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return (root->val == 1) ? true : false;
        bool lt = evaluateTree(root->left);
        bool rt = evaluateTree(root->right);
        if (root->val == 2)
            return lt | rt;
        else
            return lt & rt;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout << "Result: " << s.evaluateTree(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/evaluate-boolean-binary-tree/

Youtube:

Code Link:

algorithm:

- self explanatory

*/

/*

2331. Evaluate Boolean Binary Tree

You are given the root of a full binary tree with the following properties:

Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 
represents the boolean AND.
The evaluation of a node is as follows:

If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
Otherwise, evaluate the node's two children and apply the boolean operation of its 
value with the children's evaluations.
Return the boolean result of evaluating the root node.

A full binary tree is a binary tree where each node has either 0 or 2 children.

A leaf node is a node that has zero children.

Example 1:

Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.

Example 2:

Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.

*/

/*
************* Java Code **************

public static boolean evaluateTree(TreeNode *root)
    {
        if (root==null)
            return false;
        if (root.left == null && root.right == null)
            return (root.val == 1) ? true : false;
        boolean lt = evaluateTree(root.left);
        boolean rt = evaluateTree(root.right);
        if (root.val == 2)
            return lt | rt;
        else
            return lt & rt;
    }

*/