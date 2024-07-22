#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // TC:  O(V+E)
        // SC: O(2n)
        
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
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto &&i : adj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
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
    vector<int> adj[] = {{}, {3}, {3}, {0}, {1}, {0, 2}};
    int V = 6;
    vector<int> ans = s.topoSort(V, adj);
    cout << "Topological Sort: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/topological-sort/1

leetcode:

Youtube: https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23

algorithm:

- This algo only works for DAGs.
- Find the indegree of that the nodes in the graph.
- Think of this algo as, removing nodes from the graph, which has (indegree[node] == 0).
- The removed nodes will be stored in an aray "ans", which will have the nodes on topo sort order.
- So when we remove that node, all its neighbour nodes's indegree will decrease by 1.
- Hence we reduce the indegree. And we check if any of its neighbours indegree became 0, if yes,
  then we add that into our queue.
- We do this process until, the queue gets empty.
- The "ans" array will have the nodes in topo sort order.
- reutrn "ans" array.

To find a DAG is Cyclic or not:

- check if ans.size() == V, if yes then its an acyclic graph, or its cyclic.

*/