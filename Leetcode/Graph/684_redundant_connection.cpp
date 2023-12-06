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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // TC: O(n) * O(4 * alpha)
        // SC: O(n) * 2
        
        int n = edges.size();
        disjointSet ds(n);
        int fu = 0, fv = 0;
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (ds.findUParent(u) == ds.findUParent(v))
            {
                fu = u;
                fv = v;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        vector<int> ans{fu, fv};
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = s.findRedundantConnection(edges);
    cout << "Redundant Edge to be removed, to make the graph as cycle: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/redundant-connection/description/

Youtube: https://www.youtube.com/watch?v=FXWRE67PLL0

algorithm:

- Using Disjointset DS, we can find if 2 nodes have same Ultimate parent, is yes
  then we know, that edge is reduntant, and that edge can be removed.
- We keep updating that redundant edge values, so that, we can keep the last
  edge, and then return it.

*/

/*

684. Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, 
with one additional edge added. The added edge has two different vertices 
chosen from 1 to n, and was not an edge that already existed. The graph is 
represented as an array edges of length n where edges[i] = [ai, bi] 
indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a 
tree of n nodes. If there are multiple answers, return the answer 
that occurs last in the input.

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]


*/