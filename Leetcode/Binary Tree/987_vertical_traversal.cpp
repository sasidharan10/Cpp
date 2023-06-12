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
    void verticalTraversalUtil(TreeNode *root, int &level, map<int, vector<int>> &m)
    {
        if (!root)
            return;
        level--;
        verticalTraversalUtil(root->left, level, m);
        level++;
        m[level].push_back(root->val);
        level++;
        verticalTraversalUtil(root->right, level, m);
        level--;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> m;
        int level = 0;
        verticalTraversalUtil(root, level, m);
        vector<vector<int>> v;
        for (auto &&i : m)
        {
            v.push_back(i.second);
        }
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
    vector<vector<int>> v = s.verticalTraversal(root);
    cout << "Vertical Traversal: ";
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

*/