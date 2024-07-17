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
    void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
            parent[root->left] = root;
        if (root->right != nullptr)
            parent[root->right] = root;
        findParent(root->left, parent);
        findParent(root->right, parent);
    }
    TreeNode *dfs(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == target)
            return root;
        TreeNode *lt = dfs(root->left, target);
        TreeNode *rt = dfs(root->right, target);
        if (lt != nullptr)
            return lt;
        else if (rt != nullptr)
            return rt;
        else
            return nullptr;
    }
    string bfs(TreeNode *root, string &path, int target, unordered_map<TreeNode *, TreeNode *> &parent, unordered_map<TreeNode *, bool> &vis)
    {
        if (root == nullptr)
            return "";
        vis[root] = true;
        if (root->val == target)
            return path;
        string lt = "", rt = "", up = "";
        if (root->left != nullptr && !vis[root->left])
        {
            path.push_back('L');
            lt = bfs(root->left, path, target, parent, vis);
            path.pop_back();
        }
        if (root->right != nullptr && !vis[root->right])
        {
            path.push_back('R');
            rt = bfs(root->right, path, target, parent, vis);
            path.pop_back();
        }
        if (parent[root] != nullptr && !vis[parent[root]])
        {
            path.push_back('U');
            up = bfs(parent[root], path, target, parent, vis);
            path.pop_back();
        }
        if (lt != "")
            return lt;
        else if (rt != "")
            return rt;
        else if (up != "")
            return up;
        else
            return "";
    }
    // Brute force - converting tree into graph and perforn BFS 
    string getDirections2(TreeNode *root, int startValue, int destValue)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        parent.insert({root, nullptr});
        findParent(root, parent);
        TreeNode *source = dfs(root, startValue);
        cout << source->val << endl;
        int n = parent.size();
        cout << n << endl;
        unordered_map<TreeNode *, bool> vis;
        string path = "";
        string res = bfs(source, path, destValue, parent, vis);
        return res;
    }


    TreeNode *findLCA(TreeNode *root, int s, int d)
    {
        if (root == nullptr)
            return nullptr;
        if (root == nullptr || root->val == s || root->val == d)
            return root;
        TreeNode *lt = findLCA(root->left, s, d);
        TreeNode *rt = findLCA(root->right, s, d);
        if (rt == nullptr)
            return lt;
        else if (lt == nullptr)
            return rt;
        else
            return root;
    }
    string findPath(TreeNode *root, string &path, int target)
    {
        if (root == nullptr)
            return "";
        if (root->val == target)
            return path;
        path.push_back('L');
        string lt = findPath(root->left, path, target);
        path.pop_back();
        path.push_back('R');
        string rt = findPath(root->right, path, target);
        path.pop_back();
        if (rt == "")
            return lt;
        else if (lt == "")
            return rt;
        else
            return "";
    }

    // Optimal - Find LCA of source, dest node, from there do a dfs to both nodes.
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *lca = findLCA(root, startValue, destValue);
        string path = "";
        string source = findPath(lca, path, startValue);
        path.clear();
        string dest = findPath(lca, path, destValue);
        string res = "";
        int n = source.length();
        int m = dest.length();
        res += string(n, 'U');
        res += dest;
        return res;
    }
};
int main()
{
    Solution s;
    TreeNode *root = NULL;
    root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    cout << "Path: " << s.getDirections2(root, 3, 6) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

Youtube: https://www.youtube.com/watch?v=6GXfmgfOGeQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Tree/Step-By-Step%20Directions%20From%20a%20Binary%20Tree%20Node%20to%20Another.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*






*/

/*
************* Java Code **************



*/