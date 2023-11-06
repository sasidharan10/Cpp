#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto &&adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, adj, vis))
                    return true;
            }
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis))
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
    vector<int> adj[5];
    adj[0].assign({1});
    adj[1].assign({0, 2, 4});
    adj[2].assign({1, 3});
    adj[3].assign({2, 4});
    adj[4].assign({1, 3});
    cout << "Has Cycle ? : " << s.isCycle(5, adj);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

leetcode:

Youtube: https://www.youtube.com/watch?v=zQ3zgFypzX4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=12

algorithm:

*/
