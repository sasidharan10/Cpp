#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        int n = edges.size();
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // checking for infinite negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
    int V = 3, S = 2;
    vector<int> ans = s.bellman_ford(V, edges, S);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

leetcode:

Youtube: https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45

algorithm:

- This algo is used in undirected, weighted graphs
- For using in undirected graphs (bi-directional), we have to relax the edges from u -> v and as 
  well as from v -> u.
- This algo is also known as "Single source shortest path", since we can find the shortest path
  from a single source to all its other nodes.
- This algo will work even when the weights are negative. (meanwhile dijkstra fails with -ve weights).

- In this algo we try to relax the edges of the graphs, for n - 1 times.
- dist[source] = 0, will be initialised.
- Relaxation means, if (dist[u] + wt < dist[v]), that is I find a path from u -> v, whose distance
  is lesser than dist[v], then I update it.
- We do this relaxation for n-1 times, and the resultant dist[], is the shortest distance from
  source to every node in the graph.

- Why n-1 times?
- Because, here we try to iterate the edges from the order, which is random.
- When we do the dry-run for the relaxation of the edges, at each iteration,
  we can see, we get some smaller distance, hence dist[v] is getting updated.
- At worst case, in each iteration only 1 dist[v] gets updated. so it will take atleast
  n-1 iterationss, to update all the dist[v], with the shortest distance.
- refer video for more understanding.

- Find negative cycles:

- If any negative cycles exist, then the dist[v] would be getting reduced after each
  iteration.
- So we finally do 1 more relaxation of the edges, and check if any dist[v] is getting
  smaller or not. If yes, then negative cycle exists.



*/