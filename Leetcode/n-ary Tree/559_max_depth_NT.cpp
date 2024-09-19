#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    int solve(Node *root, int depth)
    {
        vector<Node *> temp = root->children;
        if (temp.empty())
            return depth;
        int maxi = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            maxi = max(maxi, solve(temp[i], depth + 1));
        }
        return maxi;
    }
    int maxDepth(Node *root)
    {
        // TC: O(n)
        // SC: O(depth)
        
        if(root == nullptr)
            return 0;
        return solve(root, 1);
    }
};
int main()
{
    Solution s;
    vector<Node *> l1;
    vector<Node *> l2;
    vector<Node *> l3;
    vector<Node *> l4;
    vector<Node *> l5;
    vector<Node *> l6;
    Node *root = new Node(1, l1);
    Node *root2 = new Node(2, l2);
    Node *root3 = new Node(3, l3);
    Node *root4 = new Node(4, l4);
    Node *root5 = new Node(5, l5);
    Node *root6 = new Node(6, l6);
    root->children.push_back(root3);
    root->children.push_back(root2);
    root->children.push_back(root4);
    root3->children.push_back(root5);
    root3->children.push_back(root6);
    cout << "Result: " << s.maxDepth(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Just do a dfs, and keep the depth count in a variable.
- return the max depth.

*/

/*

559. Maximum Depth of N-ary Tree

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to 
the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of 
children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

Constraints:

The total number of nodes is in the range [0, 10^4].
The depth of the n-ary tree is less than or equal to 1000.

*/

/*
************* Java Code **************

    public static int solve(Node root, int depth)
    {
        List<Node> temp = root.children;
        if (temp.isEmpty())
            return depth;
        int maxi = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            maxi = Math.max(maxi, solve(temp.get(i), depth + 1));
        }
        return maxi;
    }
    public static int maxDepth(Node root)
    {
        // TC: O(n)
        // SC: O(depth)
        
        if(root == null)
            return 0;
        return solve(root, 1);
    }

*/