#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis)
    {
        vis[node] = true;
        for (auto &&i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, st, vis);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, st, vis);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> adj[] = {{}, {3}, {3}, {0}, {1}, {0, 2}};
    int V = 6;
    vector<int> ans = s.topoSort(V, adj);
    cout << "Topological Sort: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/topological-sort/1

leetcode:

Youtube: https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=21

algorithm:

*/