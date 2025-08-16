#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Memoization
    int fibMem(int n, vector<int> &dp)
    {
        // TC: O(n)  memoization
        // SC: O(n) + O(n)

        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fibMem(n - 1, dp) + fibMem(n - 2, dp);
    }
    int fib3(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibMem(n, dp);
    }

    // Tabulation
    int fib2(int n)
    {
        if (n <= 1)
            return n;

        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Space Optimization
    int fib(int n)
    {
        if (n <= 1)
            return n;

        int prev = 1;
        int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
int main()
{
    Solution s;
    int n = 7;
    cout << "Result: " << s.fib(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/fibonacci-number/

Youtube: https://www.youtube.com/watch?v=tyB0ztf0DNY

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

509. Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that
each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:

0 <= n <= 30

*/

/*
************* Java Code **************

    public static int fibMem(int n, int[] dp) {
        // TC: O(n) memoization
        // SC: O(n) + O(n)

        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fibMem(n - 1, dp) + fibMem(n - 2, dp);
    }

    public static int fib(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return fibMem(n, dp);
    }

*/