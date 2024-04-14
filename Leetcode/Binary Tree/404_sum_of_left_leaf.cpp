#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
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
    void leftSum(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        leftSum(root->left, sum);
        leftSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        leftSum(root, sum);
        return sum;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Tree: ";
    s.inorder(root);
    cout << "\nSum of Left Leaves: " << s.sumOfLeftLeaves(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-left-leaves/

Youtube:

Code Link:

algorithm:

- We have to find the sum of "left leaf", not all left nodes.
- Hence, we have to make sure, the left node is the last node, without any children

*/

/*

404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

*/

/*
************* Java Code **************

    public static int sum;

    public static void leftSum(TreeNode root) {
        if (root == null)
            return;
        if (root.left != null && root.left.left == null && root.left.right == null)
            sum += root.left.val;
        leftSum(root.left);
        leftSum(root.right);
    }

    public static int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        leftSum(root);
        return sum;
    }

*/