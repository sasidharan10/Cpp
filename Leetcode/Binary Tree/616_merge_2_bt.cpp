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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == NULL)
        {
            return root2;
        }
        if(root2 == NULL )
        {
            return root1;
        } 
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        
        return root1;

    }
};
int main()
{
    Solution s;
    TreeNode *r1 = nullptr;
    TreeNode *r2 = nullptr;
    r1 = new TreeNode(1);
    r1->left = new TreeNode(3);
    r1->right = new TreeNode(2);
    r1->left->left = new TreeNode(5);

    r2 = new TreeNode(2);
    r2->left = new TreeNode(1);
    r2->right = new TreeNode(3);
    r2->left->right = new TreeNode(4);
    r2->right->right = new TreeNode(7);

    cout << "\nTree: ";
    s.inorder(r1);
    cout << endl;
    cout << "\nTree: ";
    s.inorder(r2);
    cout << endl;
    TreeNode *temp = s.mergeTrees(r1, r2);
    cout << "\nTree: ";
    s.inorder(temp);
    cout << endl;
    cout << "Node: " << temp->val << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

*/