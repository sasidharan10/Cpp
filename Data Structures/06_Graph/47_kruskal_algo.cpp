#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
    vector<int> parent, size;

public:
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {i, v}});
            }
        }
        sort(edges.begin(), edges.end());
        disjointSet ds(V);
        int m = edges.size();
        int mstWt = 0;
        for (int i = 0; i < m; i++)
        {
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> adj[]{{{1, 2}, {2, 1}}, {{0, 2}, {2, 1}}, {{0, 1}, {1, 1}, {4, 2}, {3, 2}}, {{2, 2}, {4, 1}}, {{2, 2}, {3, 1}}};
    int V = 5;
    cout << "Find the Sum of Weights in MST: " << s.spanningTree(V, adj) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

leetcode:

Youtube:

algorithm:

*/