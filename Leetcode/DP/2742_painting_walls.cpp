#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int paintWallsRecur(int ind, int remaining, vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        if (remaining <= 0)
            return 0;
        if (ind == n)
            return 1e9;
        int pick = cost[ind] + paintWallsRecur(ind + 1, remaining - 1 - time[ind], cost, time);
        int notPick = 0 + paintWallsRecur(ind + 1, remaining, cost, time);
        return min(pick, notPick);
    }
    // Memoization
    int paintWallsMem(int ind, int remaining, vector<int> &cost, vector<int> &time, vector<vector<int>> dp)
    {
        int n = cost.size();
        if (remaining <= 0)
            return 0;
        if (ind == n)
            return 1e9;
        if (dp[ind][remaining] != -1)
            return dp[ind][remaining];
        int pick = cost[ind] + paintWallsMem(ind + 1, remaining - 1 - time[ind], cost, time, dp);
        int notPick = 0 + paintWallsMem(ind + 1, remaining, cost, time, dp);
        return dp[ind][remaining] = min(pick, notPick);
    }
    // Tabulation
    int paintWallsTab(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int remaining = 1; remaining < n + 1; remaining++)
        {
            dp[n][remaining] = 1e9;
        }
        dp[n][0] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int remaining = 1; remaining < n + 1; remaining++)
            {
                int pick;
                if (remaining - 1 - time[ind] <= 0)
                    pick = cost[ind] + 0;
                else
                    pick = cost[ind] + dp[ind + 1][remaining - 1 - time[ind]];
                int notPick = 0 + dp[ind + 1][remaining];
                dp[ind][remaining] = min(pick, notPick);
            }
        }
        return dp[0][n];
    }
    // Space Optimization
    int paintWallsSpc(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<int> cur(n + 1, 0), ahead(n + 1, 1e9);
        ahead[0] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            fill(cur.begin(), cur.end(), 0);
            for (int remaining = 1; remaining < n + 1; remaining++)
            {
                int pick;
                if (remaining - 1 - time[ind] <= 0)
                    pick = cost[ind] + 0;
                else
                    pick = cost[ind] + ahead[remaining - 1 - time[ind]];
                int notPick = 0 + ahead[remaining];
                cur[remaining] = min(pick, notPick);
            }
            ahead = cur;
        }
        return cur[n];
    }

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        // return paintWallsRecur(0, n, cost, time);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return paintWallsMem(0, n, cost, time, dp);
        // return paintWallsTab(cost, time);
        return paintWallsSpc(cost, time);
    }
};
int main()
{
    Solution s;
    vector<int> cost = {1, 2, 3, 2}, time = {1, 2, 3, 2};
    cout << "Minimum amount of money required to paint: " << s.paintWalls(cost, time) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/painting-the-walls/

Youtube: https://www.youtube.com/watch?v=8EgvelqOIfs

algorithm:

*/