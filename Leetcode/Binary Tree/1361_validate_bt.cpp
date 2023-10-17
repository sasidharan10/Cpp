#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        // TC: O(n)
        // SC: O(n)

        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n, 0);
        // counting Indegree of each child node
        for (int node = 0; node < n; node++)
        {
            int left = leftChild[node];
            int right = rightChild[node];
            if (left != -1)
            {
                graph[node].push_back(left);
                inDegree[left]++;
            }
            if (right != -1)
            {
                graph[node].push_back(right);
                inDegree[right]++;
            }
        }
        vector<int> rootCandidates;
        for (int node = 0; node < n; ++node)
        {
            if (inDegree[node] == 0)
            {
                rootCandidates.push_back(node);
            }
        }
        // if multiple root node, return false
        if (rootCandidates.size() != 1)
            return false;
        int root = rootCandidates[0];
        // checking for multiple parents and infinite cycles
        queue<int> q;
        unordered_set<int> seen;
        q.push(root);
        seen.insert(root);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (graph.find(node) != graph.end())
            {
                for (auto &&child : graph[node])
                {
                    // already visited means, it contains a cycle
                    if (seen.find(child) != seen.end())
                        return false;
                    seen.insert(child);
                    q.push(child);
                }
            }
        }
        // n==seen.size(), it means we visited all nodes in 1 BFS, hence only 1 tree is present
        return n == seen.size();
    }
};
int main()
{
    Solution s;
    // vector<int> leftChild = {1, -1, 3, -1}, rightChild = {2, -1, -1, -1};
    vector<int> leftChild = {1, -1, 3, -1}, rightChild = {2, 3, -1, -1};
    int n = 4;
    cout << "Valid Binary Tree?: " << s.validateBinaryTreeNodes(n, leftChild, rightChild);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/validate-binary-tree-nodes

Youtube:

algorithm:

A binary tree should not have:

1. Multiple parents (every node should have only 1 parent, except root node(no parent))
2. Multiple roots (Only 1 root node should be present)
3. Infinite Cycles

*/