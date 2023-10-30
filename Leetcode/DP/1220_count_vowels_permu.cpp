#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> dp;
    // Recursion + Memoization
    long long solve(int ch, int n)
    {
        if (n == 0)
            return 1;
        if (dp[ch][n] != -1)
            return dp[ch][n];
        if (ch == a)
        {
            return dp[ch][n] = solve(e, n - 1) % mod;
        }
        else if (ch == e)
        {
            return dp[ch][n] = (solve(a, n - 1) % mod) + (solve(i, n - 1) % mod);
        }
        else if (ch == i)
        {
            return dp[ch][n] = (solve(a, n - 1) % mod) + (solve(e, n - 1) % mod) + (solve(o, n - 1) % mod) + (solve(u, n - 1) % mod);
        }
        else if (ch == o)
        {
            return dp[ch][n] = (solve(i, n - 1) % mod) + (solve(u, n - 1) % mod);
        }
        else if (ch == u)
        {
            return dp[ch][n] = (solve(a, n - 1) % mod);
        }
        return -1;
    }
    // Tabulation
    long long solveTab(int len)
    {
        vector<vector<long long>> dp(5, vector<long long>(len, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[i][0] = 1;
        }
        for (int n = 1; n < len; n++)
        {
            for (int ch = 0; ch < 5; ch++)
            {
                if (ch == a)
                {
                    dp[ch][n] = dp[e][n - 1] % mod;
                }
                else if (ch == e)
                {
                    dp[ch][n] = (dp[a][n - 1] % mod) + (dp[i][n - 1] % mod);
                }
                else if (ch == i)
                {
                    dp[ch][n] = (dp[a][n - 1] % mod) + (dp[e][n - 1] % mod) + (dp[o][n - 1] % mod) + (dp[u][n - 1] % mod);
                }
                else if (ch == o)
                {
                    dp[ch][n] = (dp[i][n - 1] % mod) + (dp[u][n - 1] % mod);
                }
                else if (ch == u)
                {
                    dp[ch][n] = (dp[a][n - 1] % mod);
                }
            }
        }
        return (dp[0][len - 1] + dp[1][len - 1] + dp[2][len - 1] + dp[3][len - 1] + dp[4][len - 1]) % mod;
    }
    // Space Optimization
    long long solveSpc(int len)
    {
        vector<long long> prev(5, 1), cur(5, 0);
        for (int n = 1; n < len; n++)
        {
            for (int ch = 0; ch < 5; ch++)
            {
                if (ch == a)
                {
                    cur[ch] = prev[e] % mod;
                }
                else if (ch == e)
                {
                    cur[ch] = (prev[a] % mod) + (prev[i] % mod);
                }
                else if (ch == i)
                {
                    cur[ch] = (prev[a] % mod) + (prev[e] % mod) + (prev[o] % mod) + (prev[u] % mod);
                }
                else if (ch == o)
                {
                    cur[ch] = (prev[i] % mod) + (prev[u] % mod);
                }
                else if (ch == u)
                {
                    cur[ch] = (prev[a] % mod);
                }
            }
            prev = cur;
        }
        return (prev[0] + prev[1] + prev[2] + prev[3] + prev[4]) % mod;
    }
    int countVowelPermutation(int n)
    {
        dp.resize(5, vector<long long>(n, -1));
        long long res = 0;
        // res += solve(a, n - 1) % mod;
        // res += solve(e, n - 1) % mod;
        // res += solve(i, n - 1) % mod;
        // res += solve(o, n - 1) % mod;
        // res += solve(u, n - 1) % mod;

        // return solveTab(n);
        return solveSpc(n);
    }
};
int main()
{
    Solution s;
    int n = 4;
    cout << "Count Vowels Permutation: " << s.countVowelPermutation(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-vowels-permutation

Youtube: https://www.youtube.com/watch?v=pMU1pwHBu1U

algorithm:

*/