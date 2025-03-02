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
    TreeNode *solve(int &ind, int depth, int n, string traversal)
    {
        if (ind >= n)
            return nullptr;

        int j = ind;
        while (j < n && traversal[j] == '-')
        {
            j++;
        }
        int dash = j - ind;

        if (dash != depth)
            return nullptr;

        ind += dash;

        int num = 0;
        while (ind < n && traversal[ind] != '-')
        {
            num = num * 10 + traversal[ind] - '0';
            ind++;
        }

        TreeNode *newNode = new TreeNode(num);
        newNode->left = solve(ind, depth + 1, n, traversal);
        newNode->right = solve(ind, depth + 1, n, traversal);
        return newNode;
    }
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.length();
        int ind = 0;
        TreeNode *root = solve(ind, 0, n, traversal);
        return root;
    }
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};
int main()
{
    Solution s;
    string str = "1-2--3--4-5--6--7";
    TreeNode *root = s.recoverFromPreorder(str);
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

Youtube: https://www.youtube.com/watch?v=WN0quIK89F0

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Recover%20a%20Tree%20From%20Preorder%20Traversal.cpp

algorithm:

- Optimal Approach:

- refer video

*/

/*

1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the
value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of
the root node is 0.
If a node has only one child, that child is guaranteed to be the left child.
Given the output traversal of this traversal, recover the tree and return its root.

Example 1:

Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:

Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:

Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

Constraints:

The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 10^9

*/

/*
************* Java Code **************

    public static int ind;

    public static TreeNode solve(int depth, int n, String traversal) {
        if (ind >= n)
            return null;

        int j = ind;
        while (j < n && traversal.charAt(j) == '-') {
            j++;
        }
        int dash = j - ind;

        if (dash != depth)
            return null;

        ind += dash;

        int num = 0;
        while (ind < n && traversal.charAt(ind) != '-') {
            num = num * 10 + traversal.charAt(ind) - '0';
            ind++;
        }

        TreeNode newNode = new TreeNode(num);
        newNode.left = solve(depth + 1, n, traversal);
        newNode.right = solve(depth + 1, n, traversal);
        return newNode;
    }

    public static TreeNode recoverFromPreorder(String traversal) {
        int n = traversal.length();
        ind = 0;
        TreeNode root = solve(0, n, traversal);
        return root;
    }

*/