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
    vector<double> largestValues(TreeNode *root)
    {
        vector<double> v;
        if (!root)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        double sum = 0;
        while (!q.empty())
        {
            double n1 = q.size();
            int n = q.size();
            while (n--)
            {
                TreeNode *temp = q.front();
                sum += temp->val;
                if (temp && temp->left)
                    q.push(temp->left);
                if (temp && temp->right)
                    q.push(temp->right);
                q.pop();
            }
            double avg = sum / n1;
            v.push_back(avg);
            sum = 0;
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
    vector<double> v = s.largestValues(root);
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

leetcode: https://leetcode.com/problems/average-of-levels-in-binary-tree/

*/