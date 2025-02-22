#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        int vis[V + 1] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            vector<int> temp;
            temp = adj[node];
            for (auto &&i : temp)
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 5, m = 4;
    vector<int> adj[n + 1];
    adj[0].assign({1, 2, 3});
    adj[2].push_back(4);
    vector<int> ans = s.bfsOfGraph(n, adj);
    cout << "BFS: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

leetcode:

algorithm:

*/