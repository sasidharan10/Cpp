#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
void topoSort(int node, vector<pair<int, int>>adj[], stack<int>&st, vector<int>&vis)
{
    vis[node]=1;
    for (auto adjacentNode : adj[node])
    {
        int v = adjacentNode.first;
        int wt = adjacentNode.second;
        if(!vis[v])
            topoSort(v, adj,st,  vis);
    }
    st.push(node);
}
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<int>vis(N, 0);
        vector<pair<int, int>>adj[N];
        stack<int>st;
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        for (int i = 0; i < N; i++)
        {
            if(!vis[i])
                topoSort(i, adj, st, vis);
        }

        
        
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    int N = 6;
    int M = 7;
    vector<int> ans = s.shortestPath(N, M, edges);
    cout << "Shortest Path from Source: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/