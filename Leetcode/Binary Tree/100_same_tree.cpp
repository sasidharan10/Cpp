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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return (p == q);
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main()
{
    Solution s;
    TreeNode *r1 = nullptr;
    r1 = new TreeNode(4);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(6);
    r1->left->left = new TreeNode(1);
    r1->left->right = new TreeNode(3);
    r1->right->left = new TreeNode(5);
    r1->right->right = new TreeNode(7);

    TreeNode *r2 = nullptr;
    r2 = new TreeNode(4);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(6);
    r2->left->left = new TreeNode(1);
    r2->left->right = new TreeNode(3);
    r2->right->left = new TreeNode(5);
    r2->right->right = new TreeNode(7);
    cout << "\nR1: ";
    s.inorder(r1);
    cout << "\nR2: ";
    s.inorder(r2);
    cout << endl;
    cout << "Same tree?: " << s.isSameTree(r1, r2);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/same-tree/

*/