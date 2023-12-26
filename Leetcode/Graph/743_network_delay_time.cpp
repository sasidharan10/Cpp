#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // TC: O(ElogV)
        // SC: O(V)
        
        vector<pair<int, int>> adj[n];
        int m = times.size();
        for (int i = 0; i < m; i++)
        {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;
        pq.push({0, k - 1});
        while (!pq.empty())
        {
            int d1 = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for (auto &&it : adj[u])
            {
                int v = it.first;
                int d2 = it.second;

                if (d1 + d2 < dist[v])
                {
                    dist[v] = d1 + d2;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 1e9)
                return -1;
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++)
        {
            if (i != k - 1 && dist[i] > ans)
                ans = dist[i];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << "Result: " << s.networkDelayTime(nums, n, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/network-delay-time/description/

Youtube: https://www.youtube.com/watch?v=hptQEIpvaxM

algorithm:

- Apply dijkstra algo, to find the shortest distance from source to all nodes.
- If any node is not reachable, return -1.
- Else return the max distance, as that will be minimum time to reach all nodes.

*/

/*

743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also
given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it
takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes
for all the n nodes to receive the signal. If it is impossible for all the
n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

*/