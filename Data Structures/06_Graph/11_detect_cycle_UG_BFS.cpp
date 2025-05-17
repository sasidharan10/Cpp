#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool bfs(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto &&adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                    return true;
            }
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
                if (bfs(i, adj, vis))
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
    cout << "Has Cycle ? : " << s.isCycle(5, adj) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

leetcode:

Youtube: https://www.youtube.com/watch?v=BPlrALf1LDU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=11&pp=iAQB

algorithm:

*/
