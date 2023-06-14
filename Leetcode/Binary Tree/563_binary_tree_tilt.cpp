#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
#include <queue>
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
    int findTiltUtil(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;
        int lt = 0, rt = 0;
        if (root->left)
            lt = findTiltUtil(root->left, sum);
        if (root->right)
            rt = findTiltUtil(root->right, sum);
        sum += abs(lt - rt);
        return lt + rt + root->val;
    }
    int findTilt(TreeNode *root)
    {
        int sum = 0;
        int lt = findTiltUtil(root, sum);
        return sum;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(7);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    cout << "Binary tree Tilt: " << s.findTilt(root);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/binary-tree-tilt/

algorithm:

-

*/