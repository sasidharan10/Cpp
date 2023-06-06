#include <iostream>
#include <algorithm>
#include <unordered_set>
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
    void findTarget(TreeNode *root, TreeNode *target, TreeNode *&ans)
    {
        if (!root)
            return;
        if (root->left)
            findTarget(root->left, target, ans);
        if (root->val == target->val)
            ans = root;
        if (root->right)
            findTarget(root->right, target, ans);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *ans;
        findTarget(cloned, target, ans);
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
    s.inorder(root);
    cout << endl;
    TreeNode *temp = s.getTargetCopy(root, root, root->right->left);
    cout << "Node: " << temp->val << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

*/