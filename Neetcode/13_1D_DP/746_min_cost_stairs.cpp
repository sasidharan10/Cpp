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
        int oneStep = cost[ind] + minCostClimbingStairsRecur(ind + 1, cost);
        int twoStep = cost[ind] + minCostClimbingStairsRecur(ind + 2, cost);
        return min(oneStep, twoStep);
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
        int oneStep = cost[ind] + minCostClimbingStairsMem(ind + 1, cost, dp);
        int twoStep = cost[ind] + minCostClimbingStairsMem(ind + 2, cost, dp);
        return dp[ind] = min(oneStep, twoStep);
    }

    // Tabulation
    int minCostClimbingStairsTab(vector<int> &cost)
    {
        // TC: O(n)
        // SC: O(n)

        int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        // You can also take a different vector to store result. I have modified same vector.
        for (int i = 2; i < n; i++)
        {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }

        return min(cost[n - 1], cost[n - 2]);
    }

    // Space Optimization
    int minCostClimbingStairsSpc(vector<int> &cost)
    {
        // TC: O(n)
        // SC: O(1)

        int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int temp = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = temp;
        }
        return min(prev1, prev2);
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

Youtube: https://www.youtube.com/watch?v=_59HE5lVuLg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Min%20Cost%20Climbing%20Stairs.cpp

algorithm: 

- Optimal Approach:

- self explanatory

*/

/*

746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you 
pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.

The total cost is 6.
 
Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/

/*   
************* Java Code **************

    public static int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 2)
            return Math.min(cost[0], cost[1]);

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int temp = cost[i] + Math.min(prev1, prev2);
            prev2 = prev1;
            prev1 = temp;
        }
        return Math.min(prev1, prev2);
    }

*/