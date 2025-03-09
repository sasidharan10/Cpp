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
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    TreeNode *solve2(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder)
    {
        if (preStart > preEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;

        int nextNode = preorder[preStart + 1];

        int j = postStart;
        while (postorder[j] != nextNode)
        {
            j++;
        }
        int num = j - postStart + 1;

        root->left = solve2(preStart + 1, postStart, preStart + num, preorder, postorder);
        root->right = solve2(preStart + num + 1, j + 1, preEnd, preorder, postorder);
        return root;
    }
    // Better
    TreeNode *constructFromPrePost2(vector<int> &preorder, vector<int> &postorder)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = preorder.size();
        TreeNode *root = solve2(0, 0, n - 1, preorder, postorder);
        return root;
    }

    TreeNode *solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> &mp)
    {
        if (preStart > preEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;

        int nextNode = preorder[preStart + 1];

        int j = mp[nextNode];

        int num = j - postStart + 1;

        root->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder, mp);
        root->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder, mp);
        return root;
    }
    // Optimal - using map to find in postorder array
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[postorder[i]] = i;
        }
        TreeNode *root = solve(0, 0, n - 1, preorder, postorder, mp);
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7}, postorder = {4, 5, 2, 6, 7, 3, 1};
    root = s.constructFromPrePost(preorder, postorder);
    cout << "Tree: ";
    s.preorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Construct%20Binary%20Tree%20from%20Preorder%20and%20Postorder%20Traversal.cpp

algorithm:

- Brute Force Approach:

- O(n) T.C for searching the root element in postOrder array.

- Optimal Approach:

- use map to fetch the root element from postOrder array. 

*/

/*

889. Construct Binary Tree from Preorder and Postorder Traversal

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree
of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

*/

/*
************* Java Code **************

    public static TreeNode solve(int preStart, int postStart, int preEnd, int[] preorder, int[] postorder,
            Map<Integer, Integer> mp) {
        if (preStart > preEnd)
            return null;

        TreeNode root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;

        int nextNode = preorder[preStart + 1];

        int j = mp.get(nextNode);

        int num = j - postStart + 1;

        root.left = solve(preStart + 1, postStart, preStart + num, preorder, postorder, mp);
        root.right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder, mp);
        return root;
    }

    public static TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = postorder.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(postorder[i], i);
        }
        TreeNode root = solve(0, 0, n - 1, preorder, postorder, mp);
        return root;
    }

*/