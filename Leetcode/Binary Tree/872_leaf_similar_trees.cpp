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
    void getLeafNodes(TreeNode *root, vector<int> &leaves)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            leaves.push_back(root->val);
        getLeafNodes(root->left, leaves);
        getLeafNodes(root->right, leaves);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1, leaves2;
        getLeafNodes(root1, leaves1);
        getLeafNodes(root2, leaves2);
        return leaves1 == leaves2;
    }
};
int main()
{
    Solution s;
    TreeNode *root1 = nullptr;
    root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode *root2 = nullptr;
    root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    cout << "Leaf-Similar Trees: " << s.leafSimilar(root1, root2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/leaf-similar-trees

Youtube:

algorithm:

- Do pre-Order traversal, so we visit the leaf nodes, from left to right and store it in an array
- Compare both arrays and return the result.

*/

/*

872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values
of those leaves form a leaf value sequence.


For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false


*/