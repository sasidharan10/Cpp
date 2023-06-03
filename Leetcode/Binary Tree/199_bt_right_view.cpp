#include <iostream>
#include <algorithm>
#include <stack>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            if (q.front())
                ans.push_back(q.front()->val);
            while (n--)
            {
                TreeNode *temp = q.front();
                if (temp && temp->right)
                    q.push(temp->right);
                if (temp && temp->left)
                    q.push(temp->left);
                q.pop();
            }
        }
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
    vector<int> ans = s.rightSideView(root);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/binary-tree-right-side-view/description/

*/