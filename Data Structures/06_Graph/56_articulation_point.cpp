#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, int tin[], int low[], vector<bool> &vis, vector<bool> &ap, vector<int> adj[])
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (int it : adj[node])
        {
            if (parent == it)
                continue;
            if (!vis[it])
            {
                dfs(it, node, tin, low, vis, ap, adj);
                low[node] = min(low[node], low[it]);
                if (tin[node] <= low[it] && parent != -1)
                    ap[node] = true;
                child++;
            }
            else
                low[node] = min(low[node], tin[it]);
        }
        if (parent == -1 && child > 1)
            ap[node] = true;
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        int tin[V];
        int low[V];
        vector<bool> vis(V, false);
        vector<bool> ap(V, false);
        timer = 1;
        dfs(0, -1, tin, low, vis, ap, adj);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i])
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        else
            return ans;
    }
};
int main()
{
    Solution s;
    int n = 7;
    vector<int> adj[n] = {{1, 2, 3}, {0}, {0, 3, 4, 5}, {0, 2}, {2, 6}, {2, 6}, {4, 5}};
    vector<int> ans = s.articulationPoints(n, adj);
    cout << "No of Articulation Points: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://www.geeksforgeeks.org/problems/articulation-point-1/1

leetcode:

Youtube: https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=56

algorithm:

*/

/*

Articulation Point - I

Given an undirected connected graph with V vertices and adjacency list adj.
You are required to find all the vertices removing which (and edges through it)
disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might
be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

Your Task:
You don't need to read or print anything. Your task is to complete the function
articulationPoints() which takes V and adj as input parameters and returns a
list containing all the vertices removing which turn the graph into two or
more disconnected components in sorted order. If there are no such vertices
then returns a list containing -1.

*/