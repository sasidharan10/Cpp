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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *ans;
        while (!que.empty())
        {
            ans = que.front();
            que.pop();
            if (ans->right)
                que.push(ans->right);
            if (ans->left)
                que.push(ans->left);
        }
        return ans->val;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    cout << "Bottom LeftMost Node Value: " << s.findBottomLeftValue(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-bottom-left-tree-value

Youtube:

algorithm:

- use plain BFS. Visit the right node first.
- Hence the last node we visit, will be the leftmost node.

*/

/*

513. Find Bottom Left Tree Value

Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:

Input: root = [2,1,3]
Output: 1

Example 2:

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

*/