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
        // TC: ~O(n) or O(n) + O(n + 2E)
        // SC: O(n) + (n)
        
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
    vector<vector<int>> adj{{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    cout << "No of provinces: " << s.numProvinces(adj, n);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

leetcode: https://leetcode.com/problems/number-of-provinces/

Youtube: https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7&pp=iAQB

algorithm:

*/