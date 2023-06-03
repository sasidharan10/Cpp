#include <iostream>
#include <algorithm>
#include <stack>
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
    void leftSum(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        leftSum(root->left, sum);
        leftSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        leftSum(root, sum);
        return sum;
    }
    int sumOfLeftLeaves2(TreeNode *root)
    {
        if (!root)
            return 0;
        else if (root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves2(root->right);
        else
            return sumOfLeftLeaves2(root->left) + sumOfLeftLeaves2(root->right);
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
    cout << "\nSum of left leaves: " << s.sumOfLeftLeaves(root);
    cout << "\nSum of left leaves: " << s.sumOfLeftLeaves2(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-left-leaves/

*/