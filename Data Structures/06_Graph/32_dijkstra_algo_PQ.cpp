#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // TC: O(ElogV)
        // SC: O(V)
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        pq.push({0, S});
        dist[S] = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (auto it : adj[u])
            {
                int v = it[0];
                int d = it[1];
                if (dis + d < dist[v])
                {
                    dist[v] = dis + d;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> adj[]{{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int V = 3;
    int S = 2;
    vector<int> ans = s.dijkstra(V, adj, S);
    cout << "Shortest Path from Source(Dijkstra Algo): " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

leetcode:

Youtube: https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=33

algorithm:

- Dijkstra Algorithm won't work with negative weights, as it will end in an infinite loop.
- By using priority_queue instead of Queue, we always update the dist[] with smallest element,
  hence we are checking for paths with smallest value possible. Eliminating paths having
  high values.
- Using queue will explore all the paths, irrespective of the path values, hence TC will be
  high.

*/