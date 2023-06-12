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
    void binaryTreePathsUtil(TreeNode *root, string str, vector<string> &v)
    {
        if (root == NULL)
            return;
        str += to_string(root->val) + "->";
        if (!root->left && !root->right)
        {
            str.pop_back();
            str.pop_back();
            v.push_back(str);
        }
        binaryTreePathsUtil(root->left, str, v);
        binaryTreePathsUtil(root->right, str, v);
        str.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> v;
        string str = "";
        binaryTreePathsUtil(root, str, v);
        return v;
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
    vector<string> v = s.binaryTreePaths(root);
    cout << "Binary Tree Paths: ";
    for (auto &&i : v)
    {
        cout << i << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/binary-tree-paths/

*/