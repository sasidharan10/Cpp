#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    TreeNode *insertNode(TreeNode *root, int n)
    {
        if (root == nullptr)
        {
            TreeNode *temp = new TreeNode(n);
            return temp;
        }
        if (n <= root->val)
            root->left = insertNode(root->left, n);
        else
            root->right = insertNode(root->right, n);
        return root;
    }
    pair<TreeNode *, int> lcaDeepestLeavesUtil(TreeNode *root)
    {
        if (!root)
            return {root, 0};
        pair<TreeNode *, int> lt = lcaDeepestLeavesUtil(root->left);
        pair<TreeNode *, int> rt = lcaDeepestLeavesUtil(root->right);
        /*
        case 1: if lt==rt, that means they are the deepes nodes, hence its parent is LCA
        case 2: if lt>rt, then lt wll have the LCA, and vise versa

        */

        if (lt.second == rt.second)
            return {root, lt.second + 1};
        else if (lt.second > rt.second)
            return {lt.first, lt.second + 1};
        else
            return {rt.first, rt.second + 1};
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        TreeNode *ans;
        pair<TreeNode *, int> t = lcaDeepestLeavesUtil(root);
        return t.first;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    TreeNode *ans = s.lcaDeepestLeaves(root);
    cout << "Lowest Common Ancestor of deepest leaves: " << ans->val;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

*/