#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = (int)(1e9 + 7);
        int m = roads.size();
        vector<vector<long long>> adj[n];
        for (int i = 0; i < m; i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            long long d1 = pq.top().first;
            long long u = pq.top().second;
            pq.pop();
            for (auto it : adj[u])
            {
                long long v = it[0];
                long long d2 = it[1];
                if (d1 + d2 < dist[v])
                {
                    dist[v] = d1 + d2;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                }
                else if (d1 + d2 == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> roads{{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int n = 7;
    cout << "Number of Ways(shortest) to Arrive at Destination: " << s.countPaths(n, roads) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

leetcode: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

Youtube: https://www.youtube.com/watch?v=_-0mx0SmYxA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=40

algorithm:

*/