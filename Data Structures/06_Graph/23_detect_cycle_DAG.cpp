#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st, bool &cyclic)
    {
        vis[node] = 1;
        for (int it : adj[node])
        {
            if (vis[it] == 0)
                dfs(it, adj, vis, st, cyclic);
            else if (vis[it] == 1)
            {
                cyclic = true;
                return;
            }
        }
        vis[node] = 2;
        st.push(node);
    }
    // Topo sort using DFS
    bool isCyclic2(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        bool cyclic = false;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, st, cyclic);
            }
        }
        if (cyclic)
            return true;
        else
            return false;
    }

    // Topo sort using kahn's ALgo (BFS)
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto &&node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto &&i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    q.push(i);
            }
        }
        cout << "Nodes with indegree: " << cnt << endl;
        if (cnt == V)
            return false;
        else
            return true;
    }
};
int main()
{
    Solution s;
    vector<int> adj[] = {{1}, {2}, {3}, {3}};
    // vector<int> adj[] = {{}, {3}, {3}, {0}, {1}, {0, 2}};
    int V = 4;
    cout << "Cyclic Graph?: " << s.isCyclic2(V, adj);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

leetcode:

Youtube: https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23&pp=iAQB

algorithm:

- Topo sort using DFS
- vis[node] == 0 means, node not visited
- vis[node] == 1 means, DFS is going on its neighbours nodes
- vis[node] == 2 means, node is visted, as well as its neighbours visited.
- So when we are doing a dfs on nodes, and we encounter (vis[node] == 1), means
  we have visited that node again, while visiting its neighbours, hence its a cyclic graph.
  
*/