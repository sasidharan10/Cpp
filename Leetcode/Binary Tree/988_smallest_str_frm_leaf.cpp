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
    string res = "";
    // Using DFS
    void smallestFromLeafDfs(TreeNode *root, string curr)
    {
        // TC : O(n) * length of longest string
        // SC : O(n) space taken for resurion system stack

        if (!root)
            return;
        curr = char('a' + root->val) + curr;
        if (!root->left && !root->right)
        {
            if (res == "" || res > curr)
                res = curr;
        }
        smallestFromLeafDfs(root->left, curr);
        smallestFromLeafDfs(root->right, curr);
    }
    // Using BFS
    string smallestFromLeafBfs(TreeNode *root)
    {
        // TC : O(n) * length of longest string
        // SC : O(n)

        queue<pair<TreeNode *, string>> que;
        string temp = "";
        temp += char('a' + root->val);
        que.push({root, temp});
        while (!que.empty())
        {
            TreeNode *node = que.front().first;
            string curr = que.front().second;
            que.pop();
            if (!node->left && !node->right)
            {
                if (res == "" || res > curr)
                    res = curr;
            }
            if (node->left)
            {
                que.push({node->left, char('a' + node->left->val) + curr});
            }
            if (node->right)
            {
                que.push({node->right, char('a' + node->right->val) + curr});
            }
        }
        return res;
    }
    string smallestFromLeaf(TreeNode *root)
    {
        smallestFromLeafDfs(root, "");
        return res;
        // return smallestFromLeafBfs(root);
    }
};

int main()
{
    Solution s;
    TreeNode *root = nullptr;
    // root = new TreeNode(25);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(2);

    // root = new TreeNode(0);
    // root->right = new TreeNode(1);

    root = new TreeNode(25);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->left = new TreeNode(0);
    cout << "Tree: ";
    s.inorder(root);
    cout << endl;
    cout << "Result: " << s.smallestFromLeaf(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/smallest-string-starting-from-leaf/

Youtube: https://www.youtube.com/watch?v=SX7dC8htok0

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Smallest%20String%20Starting%20From%20Leaf.cpp

algorithm:

- As we traverse the tree (BFS or DFS), we append the current char to the curr string from the front.
- Once we reach the leaf node, we check if the formed string is smaller than "res".
- Since we are adding the char at the start of the string, that operation will take
  O(len).

*/

/*

988. Smallest String Starting From Leaf

You are given the root of a binary tree where each node has a value in the range [0, 25] 
representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

Example 1:

Input: root = [0,1,2,3,4,3,4]
Output: "dba"

Example 2:

Input: root = [25,1,3,1,3,0,2]
Output: "adz"

Example 3:

Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"

*/

/*
************* Java Code **************

public static String res;

    public static void smallestFromLeafDfs(TreeNode root, String curr) {
        if (root == null)
            return;
        curr = (char) ('a' + root.val) + curr;
        if (root.left == null && root.right == null) {
            if (res == "" || res.compareTo(curr) > 0)
                res = curr;
        }
        smallestFromLeafDfs(root.left, curr);
        smallestFromLeafDfs(root.right, curr);
    }

    public static String smallestFromLeaf(TreeNode root) {
        res = "";
        smallestFromLeafDfs(root, "");
        return res;
    }

// using Bfs

public static class Pair {
        TreeNode node;
        String curr;

        Pair() {
        }

        Pair(TreeNode node, String curr) {
            this.node = node;
            this.curr = curr;
        }
    }

    public static String res;

    public static String smallestFromLeaf(TreeNode root) {
        res = "";
        Queue<Pair> que = new LinkedList<>();
        String temp = "";
        temp += (char) ('a' + root.val);
        que.offer(new Pair(root, temp));
        while (!que.isEmpty()) {
            Pair p = que.poll();
            TreeNode node = p.node;
            String curr = p.curr;
            if (node.left == null && node.right == null) {
                if (res.equals("") || res.compareTo(curr) > 0)
                    res = curr;
            }
            if (node.left != null) {
                que.offer(new Pair(node.left, (char) ('a' + node.left.val) + curr));
            }
            if (node.right != null) {
                que.offer(new Pair(node.right, (char) ('a' + node.right.val) + curr));
            }
        }
        return res;
    }

*/