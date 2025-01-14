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
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto &&i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
    }
    // Better
    int findCircleNum2(vector<vector<int>> &isConnected)
    {
        // TC: ~ O(n) or O(n) + O(n + 2E)
        // SC: O(n) + (n)

        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }

    // Optimal
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // TC: O(n * n) = visiting all values in the matrix
        // SC: O(n) * 2 = storing parent, size
        
        int n = isConnected.size();
        disjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
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
    vector<vector<int>> mat{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << "No of provinces: " << s.findCircleNum(mat);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

leetcode: https://leetcode.com/problems/number-of-provinces/

Youtube: https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7&pp=iAQB
Youtube: https://www.youtube.com/watch?v=ZGr5nX-Gi6Y&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=48

algorithm:

- 1) using simple dfs
- 2) using MST
- no of nodes, whose parent is itself, is the count of no of components in a graph
*/

/*

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly 
with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth 
city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 
Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

/*   
************* Java Code **************

    public static void dfs(int node, List<List<Integer>> adj, int[] vis) {
        vis[node] = 1;
        // if (adj.get(node) == null)
        //     return;
        for (int nbr : adj.get(node)) {
            if (vis[nbr] == 0)
                dfs(nbr, adj, vis);
        }
    }

    public static int findCircleNum(int[][] isConnected) {
        // TC: ~O(n) or O(n) + O(n + 2E)
        // SC: O(n) + (n)

        int n = isConnected.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] vis = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj.get(i).add(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }

*/