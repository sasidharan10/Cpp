#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfs3(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs3(it, adj, vis);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> revAdj[n];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0; // marking it unvisited
            for (auto it : adj[i])
            {
                revAdj[it].push_back(i);
            }
        }
        int cnt = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                cnt++;
                dfs3(node, revAdj, vis);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    int V = 5;
    vector<vector<int>> adj{{2, 3}, {0}, {1}, {4}, {}};
    cout << "No Of SC Components: " << s.kosaraju(V, adj) << endl;
    return 0;
}

/*

link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

leetcode:

Youtube: https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54

algorithm:

- A component is called a Strongly Connected Component(SCC) only if for every 
  possible pair of vertices (u, v) inside that component, u is reachable 
  from v and v is reachable from u.
- This algo only works for directed graphs

- Kosaraju’s Algorithm:

- Sort all the nodes by finishing time
- Reverse the links
- Count the no of Components

- Why sort by finishing nodes?
- 
- Link: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

*/
