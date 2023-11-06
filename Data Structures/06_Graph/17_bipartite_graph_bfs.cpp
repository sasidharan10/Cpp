#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool bfs(int start, vector<int> &color, vector<int> adj[])
    {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &&it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> adj[]{{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    int V = 4;
    // vector<int> adj[]{{1}, {0, 2}, {1}};
    // int V = 3;
    cout << "is Bipartite Graph?: " << s.isBipartite(V, adj);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

leetcode: https://leetcode.com/problems/is-graph-bipartite/

Youtube: https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=21

algorithm:

*/