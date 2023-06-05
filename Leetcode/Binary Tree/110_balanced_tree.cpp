#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
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
    int treeHeight(TreeNode *root)
    {
        if (!root)
            return -1;
        int lt = treeHeight(root->left);
        int rt = treeHeight(root->right);
        return max(lt, rt) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        int lt = treeHeight(root->left);
        int rt = treeHeight(root->right);
        if (abs(lt - rt) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
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
    // root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    cout << "\nTree: ";
    s.inorder(root);
    cout << "\nHeight: " << s.treeHeight(root);
    cout << "\nBalanced?: " << s.isBalanced(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/balanced-binary-tree/

*/