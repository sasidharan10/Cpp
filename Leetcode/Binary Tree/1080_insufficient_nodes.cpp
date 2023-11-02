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
    TreeNode *sufficientSubsetUtil(TreeNode *root, int limit)
    {
        if (root == NULL)
            return root;
        if (!root->left && !root->right)
        {
            if (root->val < limit)
                return NULL;
            else
                return root;
        }
        else
        {
            root->left = sufficientSubsetUtil(root->left, limit - root->val);
            root->right = sufficientSubsetUtil(root->right, limit - root->val);
            if (!root->left && !root->right)
                return NULL;
            else
                return root;
        }
    }
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        return sufficientSubsetUtil(root, limit);
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
    root->left->right = new TreeNode(-99);
    root->right->left = new TreeNode(-99);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(-99);
    root->left->right->right = new TreeNode(-99);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(-99);
    root->right->right->right = new TreeNode(14);
    int limit = 1;
    cout << "Tree: ";
    s.inorder(root);
    root = s.sufficientSubset(root, limit);
    cout << "\nBinary Tree after removing Insufficient Nodes: " << endl;
    s.inorder(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

Youtube:

algorithm:

*/