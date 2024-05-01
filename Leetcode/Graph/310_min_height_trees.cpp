#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mini;
    vector<int> ans;
    vector<vector<int>> adj;
    void bfs(int root, int n)
    {
        vector<bool> vis(n, false);
        int curr = 0;
        queue<int> que;
        que.push(root);
        vis[root] = true;
        while (!que.empty())
        {
            int sz = que.size();
            while (sz--)
            {
                int node = que.front();
                que.pop();
                for (int it : adj[node])
                {
                    if (!vis[it])
                    {
                        que.push(it);
                        vis[it] = true;
                    }
                }
            }
            curr++;
            if (curr > mini)
                return;
        }
        if (curr < mini)
        {
            mini = curr;
            ans.clear();
            ans.push_back(root);
        }
        else if (curr == mini)
        {
            ans.push_back(root);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        adj.resize(n);
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            bfs(i, n);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    int n = 6;
    // vector<vector<int>> nums{{1, 0}, {1, 2}, {1, 3}};
    // int n = 4;
    vector<int> ans = s.findMinHeightTrees(n, nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-height-trees/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/

/*
************* Java Code **************



*/