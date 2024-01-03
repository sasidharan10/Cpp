#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cnt = 0;
    void dfs(int node, int parent, vector<pair<int, int>> adj[])
    {
        for (auto &&it : adj[node])
        {
            int v = it.first;
            int state = it.second;

            if (v != parent)
            {
                if (state == 1)
                    cnt++;
                dfs(v, node, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        // TC: O(V + E)
        // SC: O(V + 2E)
        
        int m = connections.size();
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        dfs(0, -1, adj);
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> connections{{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    cout << "Result: " << s.minReorder(n, connections) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

Youtube: https://www.youtube.com/watch?v=42Z0eaopoZ8

algorithm:

- We need to find, minimum no of routes, to be inverted to make all
  nodes to reach the source '0'.
- Its also given that, it is a firected graph and there will be n-1 routes,
  i.e., no cycles will be there, and a node will have atmost 2 edges.
- hence, we make the graph as undirected graph and store value for the edges as
  '1' for original route, and '0' for duplicate route.
- We start from the source and do a DFS traversal, and check if the current node
  has '1' or '0' as state.
- '1' means, the node has edge (u -> v) and we are coming from 0, so we need to
  invert the route, hence we increase the cnt.
- '0' means, the node has edge (v -> u) and its in the direction of source 0,
  hence, no need to reverse the route, and we move to next node.
- We also check not to visit the parent node again, as it will create a cycle.

*/

/*

1466. Reorder Routes to Make All Paths Lead to the City Zero

There are n cities numbered from 0 to n - 1 and n - 1 roads such that
there is only one way to travel between two different cities
(this network form a tree). Last year, The ministry of transport
decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi]
represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0),
and many people want to travel to this city.

Your task consists of reorienting some roads such that each city
can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

Example 1:

Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such
that each node can reach the node 0 (capital).

Example 2:

Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such
that each node can reach the node 0 (capital).

Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

*/