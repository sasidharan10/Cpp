#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int climbStairsRecur(int i)
    {
        // TC: O(2^n)
        // SC: O(n)  // stack space
        
        if (i < 0)
            return 0;
        if (i == 0)
            return 1;
        int st1 = climbStairsRecur(i - 1);
        int st2 = climbStairsRecur(i - 2);
        return st1 + st2;
    }

    // Memoization
    int climbStairsMem(int i, vector<int> &dp)
    {
        // TC: O(n)
        // SC: O(n)  // stack space
        
        if (i < 0)
            return 0;
        if (i == 0)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int st1 = climbStairsMem(i - 1, dp);
        int st2 = climbStairsMem(i - 2, dp);
        return dp[i] = st1 + st2;
    }

    // Tabulation
    int climbStairsTab(int n)
    {
        // TC: O(n)
        // SC: O(n)
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int st1 = 0, st2 = 0;
            if (i > 0)
                st1 = dp[i - 1];
            if (i > 1)
                st2 = dp[i - 2];
            dp[i] = st1 + st2;
        }
        return dp[n];
    }

    // Space Optimization
    int climbStairsSpc(int n)
    {
        // TC: O(n)
        // SC: O(1)
        
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 1; i <= n; i++)
        {
            int st1 = 0, st2 = 0;
            if (i > 0)
                st1 = prev1;
            if (i > 1)
                st2 = prev2;
            int cur = st1 + st2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int climbStairs(int n)
    {
        // return climbStairsRecur(n);
        vector<int> dp(n + 1, -1);
        // return climbStairsMem(n, dp);
        // return climbStairsTab(n);
        return climbStairsSpc(n);
    }
};
int main()
{
    Solution s;
    int n = 5;
    cout << "Distinct steps to reach top: " << s.climbStairs(n);
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/climbing-stairs

Youtube: https://www.youtube.com/watch?v=mLfjzJsN8us

Code Link: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/

algorithm: 

- Brute Force Approach:

- 

- Optimal Approach:

- self explanatory

*/

/*

70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

1 <= n <= 45

*/

/*   
************* Java Code **************

    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int st1 = 0, st2 = 0;
            if (i > 0)
                st1 = dp[i - 1];
            if (i > 1)
                st2 = dp[i - 2];
            dp[i] = st1 + st2;
        }
        return dp[n];
    }

*/