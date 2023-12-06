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
    int Solve(int n, vector<vector<int>> &connections)
    {
        // TC: O(m) * 4 * alpha + O(n)
        // SC: O(n) * 2

        int m = connections.size();
        disjointSet ds(n);
        int extraEdges = 0;
        for (int i = 0; i < m; i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
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
    vector<vector<int>> connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    int n = 6;
    cout << "Minimum number of operations to make the graph connected: " << s.Solve(n, connections) << endl;
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


/*

1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections 
forming a network where connections[i] = [ai, bi] represents a connection between 
computers ai and bi. Any computer can reach any other computer directly 
or indirectly through the network.

You are given an initial computer network connections. You can extract certain 
cables between two directly connected computers, and place them between any 
pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all 
the computers connected. If it is not possible, return -1.

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

*/