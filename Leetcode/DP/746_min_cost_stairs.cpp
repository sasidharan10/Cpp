#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int minCostClimbingStairsRecur(int ind, vector<int> &cost)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = cost.size();
        if (ind == n - 1)
        {
            return cost[ind];
        }
        if (ind > n - 1)
        {
            return 0;
        }
        int one = cost[ind] + minCostClimbingStairsRecur(ind + 1, cost);
        int two = cost[ind] + minCostClimbingStairsRecur(ind + 2, cost);
        return min(one, two);
    }
    // Memoization
    int minCostClimbingStairsMem(int ind, vector<int> &cost, vector<int> &dp)
    {
        // TC: O(n)
        // SC: O(n)

        int n = cost.size();
        if (ind == n - 1)
        {
            return cost[ind];
        }
        if (ind > n - 1)
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        int one = cost[ind] + minCostClimbingStairsMem(ind + 1, cost, dp);
        int two = cost[ind] + minCostClimbingStairsMem(ind + 2, cost, dp);
        return dp[ind] = min(one, two);
    }
    // Tabulation
    int minCostClimbingStairsTab(vector<int> &cost)
    {
        // TC: O(n)
        // SC: O(n)

        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = cost[n - 1];
        for (int ind = n - 2; ind >= 0; ind--)
        {
            int one = cost[ind] + dp[ind + 1];
            int two = cost[ind] + dp[ind + 2];
            dp[ind] = min(one, two);
        }
        return min(dp[0], dp[1]);
    }
    // Space Optimization
    int minCostClimbingStairsSpc(vector<int> &cost)
    {
        // TC: O(n)
        // SC: O(1)

        int n = cost.size();
        int prev2 = 0;
        int prev1 = cost[n - 1];
        int cur = 0;
        for (int ind = n - 2; ind >= 0; ind--)
        {
            int one = cost[ind] + prev1;
            int two = cost[ind] + prev2;
            cur = min(one, two);
            prev2 = prev1;
            prev1 = cur;
        }
        return min(prev2, prev1);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // int one = minCostClimbingStairsRecur(0, cost);
        // int two = minCostClimbingStairsRecur(1, cost);
        vector<int> dp(n + 1, -1);
        // int one = minCostClimbingStairsMem(0, cost, dp);
        // int two = minCostClimbingStairsMem(1, cost, dp);
        // return min(one, two);
        // return minCostClimbingStairsTab(cost);
        return minCostClimbingStairsSpc(cost);
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Min cost: " << s.minCostClimbingStairs(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/min-cost-climbing-stairs/

Youtube:

algorithm:

*/