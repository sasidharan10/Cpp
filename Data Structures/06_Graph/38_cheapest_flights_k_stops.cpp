#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // TC: O(E + flight size)
        // SC: O(flight size)

        vector<vector<int>> adj[n];
        int f = flights.size();
        for (int i = 0; i < f; i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n, 1e9);
        // steps , node , dist
        queue<pair<int, pair<int, int>>> q;
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int d1 = q.front().second.second;
            q.pop();
            if (steps > K)
                continue;
            for (auto it : adj[node])
            {
                int v = it[0];
                int d2 = it[1];
                if (steps <= K && d1 + d2 < dist[v])
                {
                    dist[v] = d1 + d2;
                    q.push({steps + 1, {v, dist[v]}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int n = 4, src = 0, dst = 3, k = 1;
    cout << "Cheapest Flights Within K Stops: " << s.CheapestFLight(n, flights, src, dst, k) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

leetcode: https://leetcode.com/problems/cheapest-flights-within-k-stops/

Youtube: https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=38

algorithm:

*/