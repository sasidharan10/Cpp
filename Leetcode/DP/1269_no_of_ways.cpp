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
        return left + right + stay;
    }
    // Memoization
    int numWaysMem(int ind, int steps, int n, vector<vector<int>> &dp)
    {
        if (ind < 0 || ind >= n || (steps == 0 && ind != 0))
            return 0;
        if (steps == 0 && ind == 0)
            return 1;
        if (dp[ind][steps] != -1)
            return dp[ind][steps];
        int left = numWaysMem(ind - 1, steps - 1, n, dp);
        int right = numWaysMem(ind + 1, steps - 1, n, dp);
        int stay = numWaysMem(ind, steps - 1, n, dp);
        return dp[ind][steps] = left + right + stay;
    }
    // Tabulation

    // Space Optimization

    int numWays(int steps, int arrLen)
    {
        // return numWaysRecur(0, steps, arrLen);
        vector<vector<int>> dp(arrLen, vector<int>(steps + 1, -1));
        return numWaysMem(0, steps, arrLen, dp);
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