#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path)
    {
        vis[node] = 1;
        path[node] = 1;
        for (auto &&adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, adj, vis, path))
                    return true;
            }
            else if (path[adjacentNode] == 1)
            {
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, path))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<int> adj[10];
    adj[0].assign({1});
    adj[1].assign({2});
    adj[2].assign({3, 6});
    adj[3].assign({4});
    adj[4].assign({5});
    adj[5].assign({});
    adj[6].assign({4});
    adj[7].assign({8});
    adj[8].assign({9});
    adj[9].assign({7});
    // adj[9].assign({});  // breaking cycle
    cout << "Has Cycle ? : " << s.isCycle(10, adj);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

leetcode:

Youtube: https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=19

algorithm:

*/
