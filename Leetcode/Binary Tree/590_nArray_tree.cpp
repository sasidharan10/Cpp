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
    void solve(Node *root, vector<int> &res)
    {
        vector<Node *> temp = root->children;
        for (int i = 0; i < temp.size(); i++)
        {
            solve(temp[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        solve(root, res);
        return res;
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
    vector<int> ans = s.postorder(root);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/n-ary-tree-postorder-traversal

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

590. N-ary Tree Postorder Traversal

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of
children is separated by the null value (See examples)

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
0 <= Node.val <= 10^4
The height of the n-ary tree is less than or equal to 1000.

*/

/*
************* Java Code **************

    public static void solve(Node root, List<Integer> res) {
        List<Node> temp = new ArrayList<>();
        temp = root.children;
        for (int i = 0; i < temp.size(); i++) {
            solve(temp.get(i), res);
        }
        res.add(root.val);
    }

    public static List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        solve(root, res);
        return res;
    }

*/