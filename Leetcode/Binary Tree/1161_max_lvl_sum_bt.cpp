#include <bits/stdc++.h>
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
    int maxLevelSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        int maxLevel = 0;
        int lvl = 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            lvl++;
            sum = 0;
            int n = q.size();
            while (n > 0)
            {
                TreeNode *temp = q.front();
                sum += temp->val;
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                n--;
            }
            if (sum > maxi)
            {
                maxLevel = lvl;
                maxi = sum;
            }
        }
        return maxLevel;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    cout << "Maximum Level Sum of a Binary Tree: " << s.maxLevelSum(root) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/