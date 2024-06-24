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
    void getNodes(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (root == NULL)
            return;
        getNodes(root->left, arr);
        arr.push_back(root);
        getNodes(root->right, arr);
    }
    TreeNode *createBST(int low, int high, int n, vector<TreeNode *> &arr)
    {
        if (low > high)
            return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode *root = arr[mid];
        root->left = createBST(low, mid - 1, n, arr);
        root->right = createBST(mid + 1, high, n, arr);
        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> arr;
        getNodes(root, arr);
        int n = arr.size();
        int low = 0, high = n - 1;
        TreeNode *newRoot = createBST(low, high, n, arr);
        return newRoot;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    cout << "\nTree: ";
    s.inorder(root);
    root = s.balanceBST(root);
    cout << "\nTree After Modification: ";
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/balance-a-binary-search-tree

Youtube: https://www.youtube.com/watch?v=wHzpM_u7p0s

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/BST/Balance%20a%20Binary%20Search%20Tree.cpp

algorithm:

- Optimal Approach:

- We cannnot solve this problem using in-place algorithm.
- Hence we traverse the BST using inorder traversal, and store it in an
  array in sorted order.
- Then we use the "Divide and conquer" (or modified binary search) algo to create the 
  new binary tree.

*/

/*

1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the
same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never
differs by more than 1.

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]

Constraints:

The number of nodes in the tree is in the range [1, 10000].
1 <= Node.val <= 100000

*/

/*
************* Java Code **************

public static void getNodes(TreeNode root, List<TreeNode> arr) {
        if (root == null)
            return;
        getNodes(root.left, arr);
        arr.add(root);
        getNodes(root.right, arr);
    }

    public static TreeNode createBST(int low, int high, int n, List<TreeNode> arr) {
        if (low > high)
            return null;
        int mid = low + (high - low) / 2;
        TreeNode root = arr.get(mid);
        root.left = createBST(low, mid - 1, n, arr);
        root.right = createBST(mid + 1, high, n, arr);
        return root;
    }

    public static TreeNode balanceBST(TreeNode root) {
        List<TreeNode> arr = new ArrayList<>();
        getNodes(root, arr);
        int n = arr.size();
        int low = 0, high = n - 1;
        TreeNode newRoot = createBST(low, high, n, arr);
        return newRoot;
    }

*/