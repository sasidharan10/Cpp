#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        vector<vector<int>> newRoutes(routes.begin(), routes.end());
        unordered_map<int, vector<int>> mp;
        int n = routes.size();
        for (int i = 0; i < n; i++)
        {
            int m = routes[i].size();
            for (int j = 0; j < m; j++)
            {
                mp[routes[i][j]].push_back(i);
            }
        }
        int stops = mp.size();
        queue<pair<int, int>> q;
        vector<int> routesVis(n, 0);
        q.push({source, 0});
        while (!q.empty())
        {
            int stop = q.front().first;
            int busCount = q.front().second;
            if (stop == target)
                return busCount;
            q.pop();
            for (auto &&route : mp[stop])
            {
                if (!routesVis[route])
                {
                    routesVis[route] = 1;
                    for (auto &&busStop : newRoutes[route])
                    {
                        q.push({busStop, busCount + 1});
                    }
                    newRoutes[route].clear();
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    cout << "Minimum no of buses taken to reach the target: ";
    cout << s.numBusesToDestination(routes, source, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/bus-routes

Youtube: https://www.youtube.com/watch?v=R58Q0J52qzI

algorithm:

*/