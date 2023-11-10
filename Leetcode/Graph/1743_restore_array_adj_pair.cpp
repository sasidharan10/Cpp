#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, int prev, vector<int> &result, unordered_map<int, vector<int>> &adj)
    {
        result.push_back(node);
        for (auto &&it : adj[node])
        {
            if (it != prev)
                dfs(it, node, result, adj);
        }
    }
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int start;
        for (auto &&it : adj)
        {
            if (it.second.size() == 1)
            {
                start = it.first;
                break;
            }
        }
        vector<int> result;
        dfs(start, INT_MAX, result, adj);
        return result;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{2, 1}, {3, 4}, {3, 2}};
    vector<int> ans = s.restoreArray(nums);
    cout << "Original Array: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

Youtube: https://www.youtube.com/watch?v=aRsdEts7i0k

algorithm:

*/