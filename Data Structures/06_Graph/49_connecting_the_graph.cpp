#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
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
    int Solve(int n, vector<vector<int>> &edge)
    {
        // TC: O(m) * 4 * alpha + O(n)
        // SC: O(n) * 2
        
        int m = edge.size();
        disjointSet ds(n);
        int extraEdges = 0;
        for (int i = 0; i < m; i++)
        {
            int u = edge[i][0];
            int v = edge[i][1];
            if (ds.findUParent(u) == ds.findUParent(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        int countConnected = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                countConnected++;
        }
        int ans = countConnected - 1;
        if (extraEdges >= ans)
            return ans;
        else
            return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edge{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    int n = 6;
    cout << "Minimum number of operations to make the graph connected: " << s.Solve(n, edge) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/connecting-the-graph/1

leetcode: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

Youtube: https://www.youtube.com/watch?v=FYrl7iz9_ZU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=49

algorithm:

- Using kruskal's algo, we find no of extraEdges, which can be removed to connect the components.
- If Ultimate parent of 2 nodes are same, then that edge can be treated as extra edge.
- Minimum edges needed to connect all components = (No of components) - 1.
- if (extra egdes) > (No of components) - 1, then we can connect the components, or else not possible

*/