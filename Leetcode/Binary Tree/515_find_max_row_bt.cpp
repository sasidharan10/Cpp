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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        int maxValue = 0;
        while (!q.empty())
        {
            TreeNode *t = q.front();
            maxValue = t->val;
            int n = q.size();
            while (n--)
            {
                TreeNode *temp = q.front();
                if (temp && temp->left)
                    q.push(temp->left);
                if (temp && temp->right)
                    q.push(temp->right);
                if (temp->val > maxValue)
                    maxValue = temp->val;
                q.pop();
            }
            v.push_back(maxValue);
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
    cout << "Tree: ";
    s.inorder(root);
    vector<int> v = s.largestValues(root);
    cout << "\nMax value in each row: ";
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

*/