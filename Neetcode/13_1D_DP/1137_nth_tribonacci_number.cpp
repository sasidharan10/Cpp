#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int tribonacciRecur(int n)
    {
        // TC: O(3^n)
        // SC: O(n)    // Stack Space

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        return tribonacciRecur(n - 1) + tribonacciRecur(n - 2) + tribonacciRecur(n - 3);
    }

    // Memoization
    int tribonacciMem(int n, vector<int> &dp)
    {
        // TC: O(n)
        // SC: O(n)

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = tribonacciMem(n - 1, dp) + tribonacciMem(n - 2, dp) + tribonacciMem(n - 3, dp);
    }

    // Tabulation
    int tribonacciTab(int n)
    {
        // TC: O(n)
        // SC: O(n)

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    // Space Optimization
    int tribonacciSpc(int n)
    {
        // TC: O(n)
        // SC: O(1)

        int a = 0, b = 1, c = 1, d = 0;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }

    int tribonacci(int n)
    {
        // TC: O(n)
        // SC: O(1)

        // return tribonacciRecur(n);
        vector<int> dp(n + 1, -1);
        // return tribonacciMem(n, dp);
        // return tribonacciTab(n);
        return tribonacciSpc(n);
    }
};
int main()
{
    Solution s;
    int n = 25;
    cout << "Nth Tribonacci number: " << s.tribonacci(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/n-th-tribonacci-number

Youtube:

algorithm:

- We just previous values in a, b ,c and compute d, then we assign a,b,c and continue,
  until the loop ends.

*/

/*

1137. N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

*/

/*

/*
************* Java Code **************

    public int tribonacci(int n) {
        int a = 0, b = 1, c = 1, d = 0;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }

*/