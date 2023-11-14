#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // TC: O(ElogV) + O(V)
        // SC: O(E + V)

        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        vector<vector<int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        dist[1] = 0;
        pq.push({0, 1});
        parent[1] = 1;
        while (!pq.empty())
        {
            int d1 = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (auto &&it : adj[u])
            {
                int v = it[0];
                int d2 = it[1];

                if (d1 + d2 < dist[v])
                {
                    dist[v] = d1 + d2;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        if (dist[n] == -1)
            return {-1};
        vector<int> ans;
        ans.push_back(n);
        int j = n;
        // O(V)
        while (j != parent[j])
        {
            int temp = parent[j];
            ans.push_back(temp);
            j = temp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int n = 5, m = 6;
    vector<int> ans = s.shortestPath(n, m, edges);
    cout << "Shortest Path from 1 to m: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/