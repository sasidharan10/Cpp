#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solveRecur(int n, int sz)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return 1e9;
        int temp = 1e9;
        int res = 1e9;
        for (int i = 1; i <= sz; i++)
        {
            int num = i * i;
            if (n - num >= 0)
            {
                temp = 1 + solveRecur(n - num, sz);
                res = min(res, temp);
            }
        }
        return res;
    }
    // Memoization
    // Recursion
    int solveMem(int n, int sz, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return 1e9;
        if (dp[n] != -1)
            return dp[n];
        int temp = 1e9;
        int res = 1e9;
        for (int i = 1; i <= sz; i++)
        {
            int num = i * i;
            if (n - num >= 0)
            {
                temp = 1 + solveMem(n - num, sz, dp);
                res = min(res, temp);
            }
        }
        return dp[n] = res;
    }
    // Tabulation
    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int temp = 1e9;
            int res = 1e9;
            for (int j = 1; j * j <= i; j++)
            {
                temp = 1 + dp[i - j * j];
                res = min(res, temp);
            }
            dp[i] = res;
        }
        return dp[n];
    }

    int numSquares(int n)
    {
        int sz = sqrt(n);
        // return solveRecur(n, sz);
        vector<int> dp(n + 1, -1);
        // return solveMem(n, sz, dp);
        return solveTab(n);
    }
};
int main()
{
    Solution s;
    int n = 13;
    cout << "Min Perfect Squares to get the sum n: " << s.numSquares(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/perfect-squares/

Youtube: https://www.youtube.com/watch?v=7zfmLa6vzaA

algorithm: DP

*/

/*

279. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are
perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/