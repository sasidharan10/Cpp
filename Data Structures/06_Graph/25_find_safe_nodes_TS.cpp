#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> revAdj[V];
        for (int i = 0; i < V; i++)
        {
            for (int node : adj[i])
            {
                revAdj[node].push_back(i);
            }
        }

        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto &&node : revAdj[i])
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
            for (auto &&i : revAdj[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> adj[12];
    int V = 12;
    adj[0].assign({1});
    adj[1].assign({2});
    adj[2].assign({3});
    adj[3].assign({4, 5});
    adj[4].assign({6});
    adj[5].assign({6});
    adj[6].assign({7});
    adj[7].assign({});
    adj[8].assign({1, 9});
    adj[9].assign({10});
    adj[10].assign({8});
    adj[11].assign({9});
    vector<int> ans = s.eventualSafeNodes(V, adj);
    cout << "List of Safe Nodes: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

leetcode: https://leetcode.com/problems/find-eventual-safe-states/description/

Youtube: https://www.youtube.com/watch?v=2gtg3VsDGyc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=25

algorithm:

*/