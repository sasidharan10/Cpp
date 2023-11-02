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
    pair<int, int> averageOfSubtreeUtil(TreeNode *root, int &cnt)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> left = averageOfSubtreeUtil(root->left, cnt);
        pair<int, int> right = averageOfSubtreeUtil(root->right, cnt);
        int sum = left.first + right.first + root->val;
        int nodes = 1 + left.second + right.second;
        int avg = sum / nodes;
        if (root->val == avg)
            cnt++;
        return {sum, nodes};
    }
    int averageOfSubtree(TreeNode *root)
    {
        int cnt = 0;
        pair<int, int> temp = averageOfSubtreeUtil(root, cnt);
        return cnt;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);
    cout << "Count Nodes Equal to Average of Subtree: " << s.averageOfSubtree(root) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

Youtube:

algorithm:

*/