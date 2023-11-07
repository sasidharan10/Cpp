#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
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
    cout << "Cyclic Graph?: " << s.isCyclic(V, adj);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

leetcode:

Youtube: https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23&pp=iAQB

algorithm:

*/