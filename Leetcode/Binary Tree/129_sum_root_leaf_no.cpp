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
    int sumNumbersUtil(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        int temp = sum * 10 + root->val;
        if (!root->left && !root->right)
            return temp;
        int lt = 0, rt = 0;
        if (root->left)
            lt = sumNumbersUtil(root->left, temp);
        if (root->right)
            rt = sumNumbersUtil(root->right, temp);
        return lt + rt;
    }
    int sumNumbers(TreeNode *root)
    {
        return sumNumbersUtil(root, 0);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << "Tree: ";
    s.inorder(root);
    cout << endl;
    cout << "Sum Root to Leaf Numbers: " << s.sumNumbers(root);
    return 0;
}

/*

link:

leetcode:

Youtube: https://www.youtube.com/watch?v=KTwkq-MsJDw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Sum%20Root%20to%20Leaf%20Numbers.cpp

algorithm:

- As we do the dfs traversal, we add the val as the sum's last digit
  until we reach the leaf node.
- We return accumulated digits once we reach the leaf node.
- Add the sum from both children, and return it.

*/

/*

129. Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so
that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

*/

/*
************* Java Code **************

public static int sumNumbersUtil(TreeNode root, int sum) {
        if (root == null)
            return 0;
        int temp = sum * 10 + root.val;
        if (root.left == null && root.right == null)
            return temp;
        int lt = 0, rt = 0;
        if (root.left != null)
            lt = sumNumbersUtil(root.left, temp);
        if (root.right != null)
            rt = sumNumbersUtil(root.right, temp);
        return lt + rt;
    }

    public static int sumNumbers(TreeNode root) {
        return sumNumbersUtil(root, 0);
    }

*/