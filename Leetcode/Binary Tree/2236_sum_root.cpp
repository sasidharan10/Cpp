#include <iostream>
#include <algorithm>
#include <unordered_set>
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

    bool checkTree(TreeNode *root)
    {
        if (root->left->val + root->right->val == root->val)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(7);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Root sum of children: " << s.checkTree(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/root-equals-sum-of-children/description/

*/