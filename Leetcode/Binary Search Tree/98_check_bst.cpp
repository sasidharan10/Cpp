#include <iostream>
#include <algorithm>
#include <climits>
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
    bool isValidBSTUtil(TreeNode *root, long long int min, long long int max)
    {
        if (!root)
            return true;
        else if (root->val > min && root->val < max && isValidBSTUtil(root->left, min, root->val) && isValidBSTUtil(root->right, root->val, max))
            return true;
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        long long int min = -9223372036854775807;
        long long int max = 9223372036854775807;
        return isValidBSTUtil(root, min, max);
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
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Is BST?: " << s.isValidBST(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/validate-binary-search-tree/

*/