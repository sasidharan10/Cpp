#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &path, vector<int> &check)
    {
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for (int adjacentNode : graph[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, graph, vis, path, check))
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
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> check(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool temp = dfs(i, graph, vis, path, check);
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
    vector<vector<int>> graph(12);
    graph[0].assign({1});
    graph[1].assign({2});
    graph[2].assign({3});
    graph[3].assign({4, 5});
    graph[4].assign({6});
    graph[5].assign({6});
    graph[6].assign({7});
    graph[7].assign({});
    graph[8].assign({1, 9});
    graph[9].assign({10});
    graph[10].assign({8});
    graph[11].assign({9});
    vector<int> ans = s.eventualSafeNodes(graph);
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