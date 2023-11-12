#include <bits/stdc++.h>
using namespace std;
class Graph
{
    unordered_map<int, vector<pair<int, int>>> adj;
    int nodes;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        int sz = edges.size();
        for (int i = 0; i < sz; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        nodes = n;
    }

    void addEdge(vector<int> edge)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }

    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(nodes, 1e9);
        pq.push({0, node1});
        dist[node1] = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (u == node2)
                return dis;
            for (auto it : adj[u])
            {
                int v = it.first;
                int d = it.second;
                if (dis + d < dist[v])
                {
                    dist[v] = dis + d;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/design-graph-with-shortest-path-calculator

Youtube: https://www.youtube.com/watch?v=EPvZsimuqwM

algorithm:

- Dijkstra Algorithm
*/