#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
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
    bool isSymmetricUtil(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 || !r2)
            return (r1 == r2);
        return r1->val == r2->val && isSymmetricUtil(r1->left, r2->right) && isSymmetricUtil(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetricUtil(root->left, root->right);
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(1);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Is Symmetric?: " << s.isSymmetric(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/symmetric-tree/

*/