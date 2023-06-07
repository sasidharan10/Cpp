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
    int treeHeight(TreeNode *root)
    {
        if (!root)
            return -1;
        int lt = treeHeight(root->left);
        int rt = treeHeight(root->right);
        return max(lt, rt) + 1;
    }
    void leavesSum(TreeNode *root, int maxDepth, int &depth, int &sum)
    {
        if (!root)
            return;
        if (maxDepth == depth)
            sum += root->val;

        depth++;
        leavesSum(root->left, maxDepth, depth, sum);
        leavesSum(root->right, maxDepth, depth, sum);
        depth--;
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int maxDepth = treeHeight(root);
        int sum = 0;
        int depth = 0;
        leavesSum(root, maxDepth, depth, sum);
        return sum;
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
    cout << "\nDeepest Leaves Sum: " << s.deepestLeavesSum(root);
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/deepest-leaves-sum/description/

*/