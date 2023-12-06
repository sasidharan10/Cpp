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
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        // TC: O(n^2) + O(MlogM) + O(M * 4 * Alpla)
        // SC: O(M) + O(V) * 2

        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        // O(n^2)
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int u = i;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                int v = j;
                edges.push_back({dist, {u, v}});
            }
        }
        disjointSet ds(n);
        int m = edges.size();

        // O(MlogM)
        sort(edges.begin(), edges.end());
        int cost = 0;

        // O(M * 4 * Alpla)
        for (int i = 0; i < m; i++)
        {
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                cost += wt;
                ds.unionBySize(u, v);
            }
        }
        return cost;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Minimum Cost to Connect All Points: " << s.minCostConnectPoints(points) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/min-cost-to-connect-all-points/

Youtube: https://www.youtube.com/watch?v=hsr7KolYDH0

algorithm:

- Minimum spanning tree problem.
*/

/*

1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points
on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance
between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


*/