#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto temp = pq.top();
            int wt1 = temp.first;
            int node = temp.second;
            pq.pop();
            if (vis[node] == 1)
                continue;
            ans += wt1;
            vis[node] = 1;
            for (auto it : adj[node])
            {
                int adj = it[0];
                int wt2 = it[1];
                if (vis[adj] != 1)
                {
                    pq.push({wt2, adj});
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> adj[]{{{1, 2}, {2, 1}}, {{0, 2}, {2, 1}}, {{0, 1}, {1, 1}, {4, 2}, {3, 2}}, {{2, 2}, {4, 1}}, {{2, 2}, {3, 1}}};
    int V = 5;
    cout << "Find the Sum of Weights in MST: " << s.spanningTree(V, adj) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

leetcode:

Youtube: https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45

algorithm:

- A spanning tree is a tree in which we have N nodes and N-1 edges and all nodes are
  reachable from each other.
- Among all possible spanning trees of a graph, The minimum spanning tree is the one
  for which the sum of all the edge weights is the minimum.
- There are a couple of algorithms that help us to find the minimum spanning tree of a graph.
  One is Prim’s algorithm and the other is Kruskal’s algorithm.
- prims algorithm is literally a greedy algorithm, where we push all adj node in the
  PQ and only pick the nodes, having less weight, until all the nodes are visited.
  
*/