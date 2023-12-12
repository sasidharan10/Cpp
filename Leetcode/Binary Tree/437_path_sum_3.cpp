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
    unordered_map<int, int> mp;
    int count = 0;

public:
    // Brute force
    void solve(TreeNode *root, long long targetSum, int &sum)
    {
        if (!root)
            return;
        targetSum -= root->val;
        if (targetSum == 0)
        {
            sum++;
        }
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
        targetSum += root->val;
    }
    void pathSum2Util(TreeNode *root, int targetSum, int &sum)
    {
        if (!root)
            return;
        solve(root, (long long)targetSum, sum);
        pathSum2Util(root->left, targetSum, sum);
        pathSum2Util(root->right, targetSum, sum);
    }

    int pathSum2(TreeNode *root, int targetSum)
    {
        // TC: O(n^2)
        // SC: O(depth of tree)

        int sum = 0;
        pathSum2Util(root, targetSum, sum);
        return sum;
    }

    void pathSumUtil(TreeNode *root, int targetSum, long long sum)
    {
        if (!root)
            return;
        sum += root->val;
        if (sum == targetSum)
        {
            count++;
        }
        if (mp.find(sum - targetSum) != mp.end())
        {
            count += mp[sum - targetSum];
        }
        mp[sum]++;
        pathSumUtil(root->left, targetSum, sum);
        pathSumUtil(root->right, targetSum, sum);
        mp[sum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        // TC: O(n)
        // SC: O(n)
        
        long long sum = 0;
        pathSumUtil(root, targetSum, sum);
        return count;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    int targetSum = 8;
    cout << "No of paths with targetSum: " << s.pathSum(root, targetSum) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-sum-iii/

Youtube:

algorithm:

- Here the path can start from any node and end at any node,
  hence do 2 dfs traversal, where the first traversal will take each node as root
  and then traverse in all its path, and check if sum==targetSum.
- In second approach, we use a map, which stores all paths sum.
- we check if (sum - targetSum) is in the map, if yes, we add its count.
- it means that path has the sum of "targetSum" + extra paths sum
  but we get to know that, targetSum is also present, hence we increase the count.
  
*/

/*

437. Path Sum III

Given the root of a binary tree and an integer targetSum, return the
number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it
must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

*/