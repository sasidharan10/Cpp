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
    TreeNode *findNode(TreeNode *root, int target)
    {
        if (!root)
            return nullptr;
        if (root->val == target)
            return root;
        TreeNode *lt = findNode(root->left, target);
        TreeNode *rt = findNode(root->right, target);
        if (lt)
            return lt;
        if (rt)
            return rt;
        return nullptr;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        TreeNode *startNode = findNode(root, start);
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, bool> visited;
        getParent(root, parent);
        queue<TreeNode *> q;
        q.push(startNode);
        visited[startNode] = true;
        int time = -1;
        while (!q.empty())
        {
            time++;
            int sz = q.size();
            while (sz)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
                sz--;
            }
        }
        return time;
    }
};
int main()
{
    Solution s;
    TreeNode *root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    int start = 3;
    cout << "Time to get all nodes infected: " << s.amountOfTime(root, start) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

Youtube: https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32&t=2s

algorithm:

- Find the target node, using any dfs traversal.
- create a map, which stores parent of every node.
- create a visited map.
- now to BFS traversal from the start node, to all 3 direction (left, right, top)
- and in each level, we increase the time by 1.
- return the time at the end.

*/

/*

2385. Amount of Time for Binary Tree to Be Infected

You are given the root of a binary tree with unique values, and an integer
start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

*/