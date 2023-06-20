#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <vector>
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
    int leftHeight(TreeNode *root)
    {
        int ht = 0;
        while (root)
        {
            root = root->left;
            ht++;
        }
        return ht;
    }
    int rightHeight(TreeNode *root)
    {
        int ht = 0;
        while (root)
        {
            root = root->right;
            ht++;
        }
        return ht;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (lh == rh)
            return (pow(2, lh) - 1);
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    cout << "\nTree: ";
    s.inorder(root);
    cout << "\nTotal tree nodes: : " << s.countNodes(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-complete-tree-nodes/

*/