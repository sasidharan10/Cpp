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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *lt = lowestCommonAncestor(root->left, p, q);
        TreeNode *rt = lowestCommonAncestor(root->right, p, q);
        if (!rt)
            return lt;
        else if (!lt)
            return rt;
        else
            return root;
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
    TreeNode *ans = s.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << "Lowest Common Ancestor: " << ans->val;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

*/