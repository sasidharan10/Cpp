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
    TreeNode *sortedArrayToBSTUtil(vector<int> &nums, int lt, int rt)
    {
        if (lt > rt)
            return nullptr;
        int mid = (lt + rt) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, lt, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, rt);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
        return root;
    }
};
int main()
{
    Solution s;
    vector<int> v = {-10, -3, 0, 5, 9};
    TreeNode *root = nullptr;
    root = s.sortedArrayToBST(v);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

*/