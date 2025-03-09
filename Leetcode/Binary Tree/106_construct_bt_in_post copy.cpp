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
    TreeNode *solve(int inStart, int inEnd, int postStart, int postEnd, vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);

        int i = mp[rootVal];
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root->left = solve(inStart, i - 1, postStart, postStart + leftSize - 1, inorder, postorder, mp);
        root->right = solve(i + 1, inEnd, postEnd - rightSize, postEnd - 1, inorder, postorder, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = solve(0, n - 1, 0, n - 1, inorder, postorder, mp);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    root = s.buildTree(inorder, postorder);
    cout << "Tree: ";
    s.inorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Youtube: https://www.youtube.com/watch?v=y6zSY_z7Kh4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Construct%20Binary%20Tree%20from%20Inorder%20and%20Postorder%20Traversal.cpp

algorithm:

- Optimal Approach:

- Find the root node, from the postorder array, which will be the last element in that array.
- Find that root, in the inorder array.
- Elements present in left side of the root, are the left children nodes and the elements present
  in the right side of the nodes, will the right children nodes.
- Find the size of the left and right nodes.
- Based on that size, we will arrange the inStart, inEnd, postStart and postEnd, and send that
  to the recursion call, to constrct the tree.

*/

/*

106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/

/*
************* Java Code **************

    public static TreeNode solve(int inStart, int inEnd, int postStart, int postEnd, int[] inorder, int[] postorder,
            Map<Integer, Integer> mp) {
        if (inStart > inEnd)
            return null;

        int rootVal = postorder[postEnd];
        TreeNode root = new TreeNode(rootVal);

        int i = mp.get(rootVal);
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root.left = solve(inStart, i - 1, postStart, postStart + leftSize - 1, inorder, postorder, mp);
        root.right = solve(i + 1, inEnd, postEnd - rightSize, postEnd - 1, inorder, postorder, mp);
        return root;
    }

    public static TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(inorder[i], i);
        }
        TreeNode root = solve(0, n - 1, 0, n - 1, inorder, postorder, mp);
        return root;
    }

*/