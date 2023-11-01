#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool bfs(int start, vector<int> &color, vector<vector<int>> &graph)
    {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &&it : graph[node])
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
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> graph{{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    vector<vector<int>> graph{{1}, {0, 2}, {1}};
    cout << "is Bipartite Graph?: " << s.isBipartite(graph);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

leetcode: https://leetcode.com/problems/is-graph-bipartite/

Youtube: https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=21

algorithm:

*/