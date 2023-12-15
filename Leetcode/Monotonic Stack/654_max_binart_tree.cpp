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
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    TreeNode *contructTree(int start, int end, vector<int> &nums)
    {
        int n = nums.size();
        if (start < 0 || end >= n || end < start)
            return nullptr;
        int maxi = max_element(nums.begin() + start, nums.begin() + end + 1) - nums.begin();
        TreeNode *node = new TreeNode(nums[maxi]);
        node->left = contructTree(start, maxi - 1, nums);
        node->right = contructTree(maxi + 1, end, nums);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        TreeNode *node = contructTree(0, n - 1, nums);
        return node;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 2, 1, 6, 0, 5};
    TreeNode *node = s.constructMaximumBinaryTree(nums);
    s.inorder(node);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-binary-tree/description/

Youtube:

algorithm:

- We find the max element in the array, create a node for it, then 
  for left node, we send the values present in left side of that max element in the recursion call.
  same for node->right, we send the values present in the right side of that max value.
- We use "start", "end" variables, to denote the starting and ending index.
- If there is no element present in left or right side, we assign NULL.
- We do this until the array gets exhausted, and return the root.

*/

/*

654. Maximum Binary Tree

You are given an integer array nums with no duplicates. A maximum binary tree can 
be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

Example 1:

Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.

Example 2:

Input: nums = [3,2,1]
Output: [3,null,2,null,1]

*/