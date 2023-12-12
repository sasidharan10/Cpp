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
    vector<vector<int>> ans;

public:
    void pathSumUtil(TreeNode *root, int targetSum, vector<int> path)
    {
        if (!root)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right)
        {
            ans.push_back(path);
        }
        pathSumUtil(root->left, targetSum, path);
        pathSumUtil(root->right, targetSum, path);
        targetSum += root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        pathSumUtil(root, targetSum, path);
        return ans;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    vector<vector<int>> ans = s.pathSum(root, targetSum);
    cout << "Paths having target Sum: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-sum-ii/

Youtube:

algorithm:

- Its basically root to leaf sum, hence we check that condition, along with checking the 
  sum.
- We do backtracking, so once we visited the node and its children, we remove it from the
  "path" vector, and subtract its sum.
  
*/

/*

113. Path Sum II

Given the root of a binary tree and an integer targetSum, return all
root-to-leaf paths where the sum of the node values in the path equals
targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any
leaf node. A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []




*/