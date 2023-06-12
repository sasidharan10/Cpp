#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // TC: O(logn*logn*logn*N)
        // SC: O(3n)
        // BFS approach (faster)

        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> v;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            TreeNode *node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            m[x][y].insert(node->val);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
            q.pop();
        }
        for (auto &&i : m)
        {
            vector<int> temp;
            for (auto &&j : i.second)
            {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            v.push_back(temp);
        }
        return v;
    }
    void verticalTraversalUtil(TreeNode *root, int level, int depth, map<int, map<int, multiset<int>>> &m)
    {
        if (!root)
            return;
        verticalTraversalUtil(root->left, level - 1, depth + 1, m);
        m[level][depth].insert(root->val);
        verticalTraversalUtil(root->right, level + 1, depth + 1, m);
    }
    vector<vector<int>> verticalTraversal2(TreeNode *root)
    {
        // TC: O(logn*logn*logn*N)
        // SC: O(3n)
        // DFS approach

        map<int, map<int, multiset<int>>> m;
        int level = 0;
        int depth = 0;
        verticalTraversalUtil(root, level, depth, m);
        vector<vector<int>> v;
        for (auto &&i : m)
        {
            vector<int> temp;
            for (auto &&j : i.second)
            {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            v.push_back(temp);
        }
        return v;
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
    vector<vector<int>> v = s.verticalTraversal(root);
    cout << "Vertical Traversal: ";
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

*/