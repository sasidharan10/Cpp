#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, vector<int> &check)
    {
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for (int adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, adj, vis, path, check))
                {
                    check[adjacentNode] = 0;
                    return true;
                }
            }
            else if (path[adjacentNode] == 1)
            {
                check[adjacentNode] = 0;
                return true;
            }
        }
        path[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool temp = dfs(i, adj, vis, path, check);
            }
        }
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> adj[12];
    int V = 12;
    adj[0].assign({1});
    adj[1].assign({2});
    adj[2].assign({3});
    adj[3].assign({4, 5});
    adj[4].assign({6});
    adj[5].assign({6});
    adj[6].assign({7});
    adj[7].assign({});
    adj[8].assign({1, 9});
    adj[9].assign({10});
    adj[10].assign({8});
    adj[11].assign({9});
    vector<int> ans = s.eventualSafeNodes(V, adj);
    cout << "List of Safe Nodes: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

leetcode: https://leetcode.com/problems/find-eventual-safe-states/description/

Youtube: https://www.youtube.com/watch?v=uRbJ1OF9aYM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=20&t=7s

algorithm:

*/