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
    int pathSum(TreeNode *root, int &m)
    {
        if (root == NULL)
            return 0;
        int lt = max(0, pathSum(root->left, m));
        int rt = max(0, pathSum(root->right, m));
        m = max(m, lt + rt + root->val);
        return max(lt, rt) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int m = 0;
        pathSum(root, m);
        return m;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Max Path Sum: " << s.maxPathSum(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/binary-tree-maximum-path-sum/

*/