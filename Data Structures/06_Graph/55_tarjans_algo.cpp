#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, int tin[], int low[], vector<bool> &vis, vector<int> adj[], vector<vector<int>> &bridges)
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for (auto &&it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == false)
            {
                dfs(it, node, tin, low, vis, adj, bridges);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        int m = connections.size();
        for (int i = 0; i < m; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, tin, low, vis, adj, bridges);
        return bridges;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> connections{{0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {5, 8}, {6, 7}, {7, 8}, {7, 9}, {9, 10}, {9, 11}, {10, 11}};
    int n = 12;
    vector<vector<int>> ans = s.criticalConnections(n, connections);
    cout << "No of Critical Connections in a Network: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link: https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/

leetcode: https://leetcode.com/problems/critical-connections-in-a-network/

Youtube: https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=55

algorithm: 

- Using tarjan's algorithm.
- Its a DFS algo, where we track the time, minTime for every node.
- As we do the DFS traversal, we track the time taken to reach that node.
- the minTime will also be same, as we are visitng the node for first time.
- Once the DFS traversal is completed for a particular node, we check with
  its adjacents node, and update the minTime => low[node] = min(low[node], low[it]).
- if (tin[node] < low[it]), means the adjacent node has taken more time than the parent
  node during the DFS travelsal, which we had to traverse through the node to reach
  the adjacent node i.e., it was the only path. hence the path between these 2 nodes
  is a bridge. 
- Note that, we dont update minTIme low[node] = min(low[node], low[it]) with its parent
  node, as we are checking for paths, other than the path, from where it came from.

*/

/*

1192. Critical Connections in a Network

There are n servers numbered from 0 to n - 1 connected by undirected
server-to-server connections forming a network where connections[i] = [ai, bi]
represents a connection between servers ai and bi. Any server can
reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some
servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

*/