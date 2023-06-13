#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
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
    void getParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        getParent(root->left, parent);
        getParent(root->right, parent);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // TC: O(3n)
        // SC: O(3n)

        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parent;
        getParent(root, parent);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        int cur_level = 0;
        visited[target] = true;
        while (!q.empty())
        {
            if (cur_level == k)
                break;
            else
                cur_level++;
            int n = q.size();
            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                // left
                if (temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                // right
                if (temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                // top
                if (parent[temp] && !visited[parent[temp]])
                {
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        // for (auto &&i : parent)
        // {
        //     cout << i.first->val << " : " << i.second->val << endl;
        // }
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    cout << "\nTree: ";
    s.inorder(root);
    cout << endl;
    vector<int> v = s.distanceK(root, root->left, 2);
    cout << "All Nodes Distance K in Binary Tree: ";
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

algorithm:

- to travel upwards, we use a map to store the parent nodes of every nodes.
- if the target value is given, instead of the node, then we have to search for that element.
- We mark the nodes as visited, since we will be going on all three directions.

*/