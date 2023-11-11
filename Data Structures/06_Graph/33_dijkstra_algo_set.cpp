#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;
        while (!st.empty())
        {
            auto node = *st.begin();
            int dis = node.first;
            int u = node.second;
            st.erase(node);
            for (auto it : adj[u])
            {
                int v = it[0];
                int d = it[1];
                if (dis + d < dist[v])
                {
                    if (dist[v] != 1e9)
                        st.erase({dist[v], v});
                    dist[v] = dis + d;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> adj[]{{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int V = 3;
    int S = 2;
    vector<int> ans = s.dijkstra(V, adj, S);
    cout << "Shortest Path from Source(Dijkstra Algo): " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

leetcode:

Youtube: https://www.youtube.com/watch?v=PATgNiuTP20&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=34

algorithm:

- Dijkstra Algorithm won't work with negative weights, as it will end in an infinite loop.

*/