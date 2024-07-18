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
        // TC: O(n) + O(n) + O(n)
        // SC: O(n)

        unordered_map<TreeNode *, TreeNode *> parent;
        parent.insert({root, nullptr});
        findParent(root, parent);
        TreeNode *source = dfs(root, startValue);
        int n = parent.size();
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
        // TC: O(n) + O(n)
        // SC: O(n)

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

- find shortest path between source node and destination node.
- We convert this tree into graph, by having a map, which keeps note of parent nodes.
- We perform a normal DFS, and find the source node.
- From the source node, we perform a BFS to the destination node.
- Since we are using a BFS traversal, the path will definetly be the shortest one.

- Optimal Approach:

- We find the LCA of source and destination node.
- From there we perform the DFS traversal to both nodes from LCA node.
- For the source node, the path will be only upwards (towards LCA), hence whatever path is generated
  (like 'LRLR' or 'RR'), it will be replaced by 'U'(like 'UUUU' or 'UU').
- for the path LCA to destination, we keep as it is.
- We concatenate both path and return it.

*/

/*

2096. Step-By-Step Directions From a Binary Tree Node to Another

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value 
from 1 to n. You are also given an integer startValue representing the value of the start 
node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step 
directions of such path as a string consisting of only the uppercase letters 'L', 'R', 
and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Example 1:

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:

Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 
Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue

*/

/*
************* Java Code **************

    public static TreeNode findLCA(TreeNode root, int s, int d) {
        if (root == null)
            return null;
        if (root == null || root.val == s || root.val == d)
            return root;
        TreeNode lt = findLCA(root.left, s, d);
        TreeNode rt = findLCA(root.right, s, d);
        if (rt == null)
            return lt;
        else if (lt == null)
            return rt;
        else
            return root;
    }

    public static StringBuilder findPath(TreeNode root, StringBuilder path, int target) {
        if (root == null)
            return new StringBuilder();
        if (root.val == target) {
            return new StringBuilder(path);
        }
        path.append('L');
        StringBuilder lt = findPath(root.left, path, target);
        path.deleteCharAt(path.length() - 1);
        path.append('R');
        StringBuilder rt = findPath(root.right, path, target);
        path.deleteCharAt(path.length() - 1);
        if (rt.isEmpty())
            return lt;
        else if (lt.isEmpty())
            return rt;
        else
            return new StringBuilder();
    }

    public static String getDirections(TreeNode root, int startValue, int destValue) {

        TreeNode lca = findLCA(root, startValue, destValue);

        StringBuilder path = new StringBuilder();
        StringBuilder source = findPath(lca, path, startValue);

        StringBuilder path2 = new StringBuilder();
        StringBuilder dest = findPath(lca, path2, destValue);

        StringBuilder res = new StringBuilder();
        int n = source.length();
        for (int i = 0; i < n; i++) {
            res.append('U');
        }
        res.append(dest);
        return res.toString();
    }

*/