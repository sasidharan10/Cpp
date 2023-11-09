#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        queue<int> q;
        vector<int> dist(N, 1e9);
        vector<int> adj[N];

        // undirected graph
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};
int main()
{
    Solution s;
    int n = 9, m = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    int src = 0;
    vector<int> ans = s.shortestPath(edges, n, m, src);
    cout << "Shortest Path from src to every node: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

leetcode:

Youtube: https://www.youtube.com/watch?v=C4gxoTaI71U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=28

algorithm:

*/