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
    void inorderTraversal(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
    void recoverTreeUtil2(TreeNode *root, vector<int> v, int &index)
    {
        if (root == NULL)
            return;

        recoverTreeUtil2(root->left, v, index);
        if (root->val != v[index])
        {
            root->val = v[index];
        }
        index++;
        recoverTreeUtil2(root->right, v, index);
    }
    void recoverTree2(TreeNode *root)
    {
        // TC: O(2n) + O(nlogn)
        // SC: O(n)

        if (!root)
            return;
        vector<int> v;
        inorderTraversal(root, v);

        sort(v.begin(), v.end());

        int index = 0;
        recoverTreeUtil2(root, v, index);
    }

    void recoverTree(TreeNode *root)
    {
        // TC: O(n)
        // SC: O(1)
        
        TreeNode *cur = root;
        TreeNode *before = nullptr;
        TreeNode *first = nullptr;
        TreeNode *middle = nullptr;
        TreeNode *last = nullptr;
        while (cur)
        {
            if (!cur->left)
            {
                if (before && before->val > cur->val)
                {
                    if (!first)
                    {
                        first = before;
                        middle = cur;
                    }
                    else
                        last = cur;
                }
                before = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    if (before->val > cur->val)
                    {
                        if (!first)
                        {
                            first = before;
                            middle = cur;
                        }
                        else
                            last = cur;
                    }
                    before = cur;
                    cur = cur->right;
                }
            }
        }
        if (first && last)
        {
            swap(first->val, last->val);
        }
        else
        {
            swap(first->val, middle->val);
        }
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(7);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    cout << "\nTree Before fixing: ";
    s.inorder(root);
    s.recoverTree(root);
    cout << "\nTree after fixing: ";
    s.inorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/recover-binary-search-tree/

*/