#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<pair<int, double>>> mp;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        while (!pq.empty())
        {
            double prob = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (u == end_node)
                return prob;
            for (auto &&it : mp[u])
            {
                int v = it.first;
                double p = it.second;
                if (prob * p > dist[v])
                {
                    dist[v] = prob * p;
                    pq.push({dist[v], v});
                }
            }
        }
        return 0.0;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    int n = 3, start_node = 0, end_node = 2;
    vector<double> succProb{0.5, 0.5, 0.3};
    cout << "Result: " << s.maxProbability(n, edges, succProb, start_node, end_node) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-with-maximum-probability/description/

Youtube:

algorithm:

- Dijkstra Algorithm

*/