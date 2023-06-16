#include <iostream>
#include <algorithm>
#include <climits>
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
    void minDiffInBSTUtil(TreeNode *root, int &prev, int &minDiff)
    {
        if (root == NULL)
            return;
        minDiffInBSTUtil(root->left, prev, minDiff);
        minDiff = min(abs(root->val - prev), minDiff);
        prev = root->val;
        minDiffInBSTUtil(root->right, prev, minDiff);
    }
    int minDiffInBST(TreeNode *root)
    {
        int prev = INT_MAX;
        int minDiff = INT_MAX;
        minDiffInBSTUtil(root, prev, minDiff);
        return minDiff;
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
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(7);
    cout << "\nTree: ";
    s.inorder(root);
    cout << "\nMin Difference: " << s.minDiffInBST(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

Algorithm: 

- We traverse by inorder, hence it will be a sorted traversal. then update the difference between,
  2 consecutive values.

- another approach will be to store the inorder traversal values in vector, then find the differnce between 
  2 consecutive values.

*/