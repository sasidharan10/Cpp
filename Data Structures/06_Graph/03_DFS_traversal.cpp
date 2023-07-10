#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);
        for (auto &&i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // TC: O(n + 2*E)
        // SC: O(3n)
        
        vector<int> ans;
        vector<int> vis(V + 1, 0);
        int start=0;
        dfs(start, adj, vis, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 5;
    vector<int> adj[n + 1];
    adj[0].assign({2, 3, 1});
    adj[2].push_back(4);
    vector<int> ans = s.dfsOfGraph(n, adj);
    cout << "DFS: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

leetcode:

algorithm:

*/