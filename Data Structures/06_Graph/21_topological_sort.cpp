#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis)
    {
        vis[node] = true;
        for (auto &&i : adj[node])
        {
            if (!vis[i])
                dfs(i, adj, st, vis);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // TC: O(V+E)+O(V)
        // SC: O(2n)
        
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, st, vis);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
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

Youtube: https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=21

algorithm:

- The topological sorting of a directed acyclic graph is nothing but the 
  linear ordering of vertices such that if there is an edge between 
  node u and v(u -> v), node u appears before v in that ordering.
- Topological sorting only exists in Directed Acyclic Graph (DAG).

- Implementation:

- We must traverse all components of the graph.
- Make sure to carry a visited array(all elements are initialized to 0) 
  and a stack data structure, where we are going to store the nodes 
  after completing the DFS call.
- In the DFS call, first, the current node is marked as visited. Then DFS 
  call is made for all its adjacent nodes.
- After visiting all its adjacent nodes, DFS will backtrack to the previous 
  node and meanwhile, the current node is pushed into the stack.
- Finally, we will get the stack containing one of the topological sortings of the graph.

- TC: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. 
  There can be at most V components. So, another O(V) time complexity.

- SC: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the 
  stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

*/