#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[10]{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    int mod = 1e9 + 7;
    // Recursion
    long long knightDialerRecur(int ind, int n)
    {
        if (n == 0)
            return 1;
        long long ans = 0;
        for (auto &&it : adj[ind])
        {
            ans = (ans + knightDialerRecur(it, n - 1) % mod);
        }
        return ans;
    }
    // Memoization
    long long knightDialerMem(int ind, int n, vector<vector<long long>> &dp)
    {
        if (n == 0)
            return 1;
        long long ans = 0;
        if (dp[ind][n] != -1)
            return dp[ind][n];
        for (auto &&it : adj[ind])
        {
            ans = (ans + knightDialerMem(it, n - 1, dp) % mod);
        }
        return dp[ind][n] = ans;
    }
    // Tabulation
    int knightDialerTab(int N)
    {
        if (N == 1)
            return 10;
        long long ans = 0;
        vector<vector<long long>> dp(N, vector<long long>(10, 0));
        for (int ind = 0; ind < 10; ind++)
        {
            dp[0][ind] = 1;
        }

        for (int n = 1; n < N; n++)
        {
            for (int ind = 0; ind < 10; ind++)
            {
                ans = 0;
                for (auto &&it : adj[ind])
                {
                    ans = (ans + dp[n - 1][it] % mod);
                }
                dp[n][ind] = ans;
            }
        }
        ans = 0;
        for (int ind = 0; ind < 10; ind++)
        {
            ans = (ans + dp[N - 1][ind]) % mod;
        }
        return ans;
    }
    // Space Optimization
    int knightDialerSpc(int N)
    {
        if (N == 1)
            return 10;
        long long ans = 0;
        vector<long long> prev(10, 1), cur(10, 0);
        for (int n = 1; n < N; n++)
        {
            for (int ind = 0; ind < 10; ind++)
            {
                ans = 0;
                for (auto &&it : adj[ind])
                {
                    ans = (ans + prev[it] % mod);
                }
                cur[ind] = ans;
            }
            prev = cur;
        }
        ans = 0;
        for (int ind = 0; ind < 10; ind++)
        {
            ans = (ans + prev[ind]) % mod;
        }
        return ans;
    }
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        long long ans = 0;
        vector<vector<long long>> dp(10, vector<long long>(n, -1));
        for (int ind = 0; ind < 10; ind++)
        {
            // ans = (ans + knightDialerRecur(ind, n - 1)) % mod;
            ans = (ans + knightDialerMem(ind, n - 1, dp)) % mod;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // int n = 1;
    // int n = 3;
    int n = 3131;
    // cout << "Result: " << s.knightDialer(n) << endl;
    // cout << "Result: " << s.knightDialerTab(n) << endl;
    cout << "Result: " << s.knightDialerSpc(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/knight-dialer

Youtube: https://www.youtube.com/watch?v=pOmSGFPcMjQ

algorithm:

*/

/*

935. Knight Dialer

The chess knight has a unique movement, it may move two squares vertically and one
square horizontally, or two squares horizontally and one square vertically
(with both forming the shape of an L).
The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only
stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then
you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.



Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any
numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34,
38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

*/