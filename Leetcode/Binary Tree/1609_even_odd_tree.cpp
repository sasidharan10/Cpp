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
    bool isEvenOddTree(TreeNode *root)
    {
        // TC: O(n)
        // SC: O(2 ^ h)

        bool lvl = true;
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *temp;
        while (!que.empty())
        {
            int n = que.size();
            int prev = -1;
            while (n > 0)
            {
                temp = que.front();
                que.pop();
                if (lvl)
                {
                    if (temp->val % 2 == 0)
                    {
                        return false;
                    }
                    if (prev != -1 && prev >= temp->val)
                        return false;
                    else
                        prev = temp->val;
                }
                else
                {
                    if (temp->val % 2 != 0)
                    {
                        return false;
                    }
                    if (prev != -1 && prev <= temp->val)
                        return false;
                    prev = temp->val;
                }
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
                n--;
            }
            lvl = !lvl;
        }
        return true;
    }
};
int main()
{
    Solution s;
    TreeNode *root = NULL;
    root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(2);
    cout << "Is Even-Odd Tree?: " << s.isEvenOddTree(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/even-odd-tree

Youtube:

algorithm:

- Optimal Approach:

- Do plain BFS and check if at odd lvl, the current element is even and vise versa.
- Also keep track of previous element in tht current lvl, using a "prev" variable.

*/

/*






*/