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
    void util(TreeNode *root, string &ans)
    {
        if (!root)
            return;
        ans += to_string(root->val);
        if (!root->left && root->right)
            ans += "()";
        if (root->left)
        {
            util(root->left, ans += "(");
            ans += ")";
        }
        if (root->right)
        {
            util(root->right, ans += "(");
            ans += ")";
        }
    }
    string tree2str(TreeNode *root)
    {
        string ans = "";
        util(root, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    cout << "String Representation of Binary tree: " << s.tree2str(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/construct-string-from-binary-tree

Youtube: https://www.youtube.com/watch?v=KZLMac8vUVw

algorithm:

- Using pre-order traversal
- when visiting a node, we append that value to the string.
- If no child, then we leave it as empty.
- If the node has left child, but no right child, we add "()" for the left child,
  so we can recognize which child is empty.
- If the node has right child, but no left child, we leave it as empty,
  as representing left child as empty itself is enough.

*/

/*

606. Construct String from Binary Tree

Given the root of a binary tree, construct a string consisting of parenthesis
and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping
relationship between the string and the original binary tree.

Example 1:

Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need
to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit
the first parenthesis pair to break the one-to-one mapping relationship
between the input and the output.

*/