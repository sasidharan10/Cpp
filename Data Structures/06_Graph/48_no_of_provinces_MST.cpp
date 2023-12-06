#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
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
    int numProvinces(vector<vector<int>> mat, int V)
    {
        int n = mat.size();
        int m = mat[0].size();
        disjointSet ds(V);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> v{{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    cout << "No of provinces: " << s.numProvinces(v, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

leetcode: https://leetcode.com/problems/number-of-provinces/

Youtube: https://www.youtube.com/watch?v=ZGr5nX-Gi6Y&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=48

algorithm:

- Using MST
- no of nodes, whose parent is itself, is the count of no of components in a graph
*/