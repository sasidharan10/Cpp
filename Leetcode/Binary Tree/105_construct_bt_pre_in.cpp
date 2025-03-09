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
    TreeNode *solve(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp)
    {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        int i = mp[rootVal];
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root->left = solve(preStart + 1, preStart + leftSize, inStart, i - 1, preorder, inorder, mp);
        root->right = solve(preEnd - rightSize + 1, preEnd, i + 1, inEnd, preorder, inorder, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = solve(0, n - 1, 0, n - 1, preorder, inorder, mp);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    root = s.buildTree(preorder, inorder);
    cout << "Tree: ";
    s.inorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Youtube: https://www.youtube.com/watch?v=G5c1wM3Kpuw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal.cpp

algorithm:

- Optimal Approach:

- Find the root node, from the preorder array, which will be the first element in that array.
- Find that root, in the inorder array.
- Elements present in left side of the root, are the left children nodes and the elements present
  in the right side of the nodes, will the right children nodes.
- Find the size of the left and right nodes.
- Based on that size, we will arrange the inStart, inEnd, preStart and preEnd, and send that
  to the recursion call, to constrct the tree.

*/

/*

105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 
Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

*/

/*
************* Java Code **************

    public static TreeNode solve(int preStart, int preEnd, int inStart, int inEnd, int[] preorder, int[] inorder,
            Map<Integer, Integer> mp) {
        if (inStart > inEnd)
            return null;

        int rootVal = preorder[preStart];
        TreeNode root = new TreeNode(rootVal);

        int i = mp.get(rootVal);
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        root.left = solve(preStart + 1, preStart + leftSize, inStart, i - 1, preorder, inorder, mp);
        root.right = solve(preEnd - rightSize + 1, preEnd, i + 1, inEnd, preorder, inorder, mp);
        return root;
    }

    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = inorder.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(inorder[i], i);
        }
        TreeNode root = solve(0, n - 1, 0, n - 1, preorder, inorder, mp);
        return root;
    }

*/