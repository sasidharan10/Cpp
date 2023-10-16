#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    // Recursion
    int numWaysRecur(int ind, int steps, int n)
    {
        if (ind < 0 || ind >= n || (steps == 0 && ind != 0))
            return 0;
        if (steps == 0 && ind == 0)
            return 1;
        int left = numWaysRecur(ind - 1, steps - 1, n);
        int right = numWaysRecur(ind + 1, steps - 1, n);
        int stay = numWaysRecur(ind, steps - 1, n);
        return (left + right + stay) % mod;
    }
    // Memoization
    int numWaysMem(int ind, int steps, int n, vector<vector<long long>> &dp)
    {
        if (ind < 0 || ind >= n || (steps == 0 && ind != 0))
            return 0;
        if (steps == 0 && ind == 0)
            return 1;
        if (dp[ind][steps] != -1)
            return dp[ind][steps];
        long long left = numWaysMem(ind - 1, steps - 1, n, dp) % mod;
        long long right = numWaysMem(ind + 1, steps - 1, n, dp) % mod;
        long long stay = numWaysMem(ind, steps - 1, n, dp) % mod;
        return dp[ind][steps] = (left + right + stay) % mod;
    }
    // Tabulation
    int numWaysTab(int st, int n)
    {
        vector<vector<int>> dp(st + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int steps = 1; steps <= st; steps++)
        {
            for (int ind = 0; ind < n; ind++)
            {
                int stay = 0, left = 0, right = 0;
                stay = dp[steps - 1][ind];
                if (ind - 1 >= 0)
                    left = dp[steps - 1][ind - 1];
                if (ind + 1 < n)
                    right = dp[steps - 1][ind + 1];
                dp[ind][steps] = (left + right + stay) % mod;
            }
        }
        for (auto &&i : dp)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        return dp[st][n - 1];
    }
    // Space Optimization

    int numWays(int steps, int arrLen)
    {
        // return numWaysRecur(0, steps, arrLen);
        // arrLen = min(arrLen, (steps / 2) + 1);
        vector<vector<long long>> dp(arrLen, vector<long long>(steps + 1, -1));
        // return numWaysMem(0, steps, arrLen, dp);
        return numWaysTab(steps, arrLen);
    }
};
int main()
{
    Solution s;
    // int steps = 3, n = 2;
    int steps = 2, n = 4;
    cout << "Number of Ways to Stay in the Same Place After Some Steps: " << s.numWays(steps, n) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/