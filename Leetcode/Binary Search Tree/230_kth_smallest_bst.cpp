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
    void kthSmallestUtil(TreeNode *root, int &k, int &ans)
    {
        if (!root)
            return;
        if (ans == INT_MAX)
            kthSmallestUtil(root->left, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->val;
            return;
        }
        if (ans == INT_MAX)
            kthSmallestUtil(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = INT_MAX;
        kthSmallestUtil(root, k, ans);
        return ans;
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
    cout << "kth smallest: " << s.kthSmallest(root, 3);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

*/