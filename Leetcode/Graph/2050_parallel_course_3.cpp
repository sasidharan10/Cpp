#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> adj[n];
        for (int i = 0; i < relations.size(); i++)
        {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);
        }
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto &&node : adj[i])
            {
                inDegree[node]++;
            }
        }
        queue<int> q;
        vector<int> maxTime(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                maxTime[i] = time[i];
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &&v : adj[u])
            {
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return *max_element(maxTime.begin(), maxTime.end());
    }
};
int main()
{
    Solution s;
    int n = 5;
    vector<vector<int>> relations = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time = {1, 2, 3, 4, 5};
    cout << "Minimum months to complete all course: " << s.minimumTime(n, relations, time);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/parallel-courses-iii/

Youtube: https://www.youtube.com/watch?v=743cYtf3DJI

algorithm: Topological sort

*/