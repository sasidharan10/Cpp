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
    void printTree(TreeNode *root)
    {
        while (root)
        {
            cout << root->val << " ";
            root = root->right;
        }
    }
    void buildTree(TreeNode *root, TreeNode *&ptr)
    {
        if (!root)
            return;
        buildTree(root->left, ptr);
        ptr->right = new TreeNode(root->val);
        ptr = ptr->right;
        buildTree(root->right, ptr);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *head = new TreeNode(0);
        TreeNode *ptr = head;
        buildTree(root, ptr);
        return head->right;
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
    cout << "\nTree Before fixing: ";
    s.inorder(root);
    TreeNode *head = s.increasingBST(root);
    cout << "\nTree after fixing: ";
    s.printTree(head);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/increasing-order-search-tree/

*/