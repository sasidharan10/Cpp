#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long long int>> q;
        long long int ans = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            int n = q.size();
            long long int first, last;
            long long int minLevel = q.front().second;
            for (int i = 0; i < n; i++)
            {
                long long int cur_id = q.front().second - minLevel;
                TreeNode *node = q.front().first;

                if (i == 0)
                    first = cur_id;
                if (i == n - 1)
                    last = cur_id;
                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
                q.pop();
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(9);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Max Width of a Binary tree: " << s.widthOfBinaryTree(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-width-of-binary-tree/

*/