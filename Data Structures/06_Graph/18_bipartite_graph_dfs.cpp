#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int cl, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = cl;
        for (auto &&adjacentNode : graph[node])
        {
            if (color[adjacentNode] == -1)
            {
                if (dfs(adjacentNode, !cl, color, graph) == false)
                    return false;
            }
            else if (color[adjacentNode] == color[node])
                return false;
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
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>>{{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    vector<vector<int>> graph{{1}, {0, 2}, {1}};
    cout << "is Bipartite Graph?: " << s.isBipartite(graph);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

leetcode: https://leetcode.com/problems/is-graph-bipartite/

Youtube: https://www.youtube.com/watch?v=KG5YFfR0j8A&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=18&t=2s

algorithm:

*/