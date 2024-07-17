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
    TreeNode *deleteNodes(TreeNode *root, unordered_set<int> &delNodes, vector<TreeNode *> &res)
    {
        if (root == nullptr)
            return nullptr;
        root->left = deleteNodes(root->left, delNodes, res);
        root->right = deleteNodes(root->right, delNodes, res);
        if (delNodes.find(root->val) != delNodes.end())
        {
            if (root->left != nullptr)
                res.push_back(root->left);
            if (root->right != nullptr)
                res.push_back(root->right);
            return nullptr;
        }
        else
            return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> res;
        unordered_set<int> delNodes(to_delete.begin(), to_delete.end());
        deleteNodes(root, delNodes, res);
        if (delNodes.find(root->val) == delNodes.end())
            res.push_back(root);
        return res;
    }
};
int main()
{
    Solution s;
    TreeNode *root = NULL;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> nums{3, 5};
    vector<TreeNode *> ans = s.delNodes(root, nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        s.inorder(i);
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/delete-nodes-and-return-forest

Youtube: https://www.youtube.com/watch?v=z-pX53sYwWI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Delete%20Nodes%20And%20Return%20Forest.cpp

algorithm:

- Optimal Approach:

- We use post order DFS traversal here.
- After visited all child nodes, we check if the current nodes needs to be deleted.
- If yes, then we add its children to the result array, and return null.
- or else we return the node itself.
- By this technique, we are able to add the children to the result array, and
  since we are return 'null', the current node is unlinked by its parent node(deleted).
- By using post order traversal, we also ensure that, all the nodes below the current
  node is already processed, so we don't need to worry about deleteing the current node.
  

*/

/*

1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.

*/

/*
************* Java Code **************



*/