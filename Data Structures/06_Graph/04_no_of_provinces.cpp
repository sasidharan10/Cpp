#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
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
    int numProvinces(vector<vector<int>> mat, int V)
    {
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (mat[i][j] && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
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

link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

leetcode:

algorithm:

*/