#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int numOfArraysRecur(int n, int k, int val, int m)
    {
        int mod = 1e9 + 7;
        if (n == 0)
        {
            if (k == 0)
                return 1;
            else
                return 0;
        }
        long long ans = 0;
        for (int j = 1; j <= m; j++)
        {
            if (j > val && k > 0)
            {
                ans += numOfArraysRecur(n - 1, k - 1, j, m) % mod;
            }
            else if (j <= val)
                ans += numOfArraysRecur(n - 1, k, val, m) % mod;
        }
        return ans;
    }
    // Memoization
    int numOfArraysMem(int n, int k, int val, int m, vector<vector<vector<int>>> &dp)
    {
        int mod = 1e9 + 7;
        if (n == 0)
        {
            if (k == 0)
                return 1;
            else
                return 0;
        }
        if (dp[n][k][val] != -1)
            return dp[n][k][val];
        long long ans = 0;
        for (int j = 1; j <= m; j++)
        {
            if (j > val && k > 0)
            {
                ans += numOfArraysMem(n - 1, k - 1, j, m, dp) % mod;
            }
            else if (j <= val)
                ans += numOfArraysMem(n - 1, k, val, m, dp) % mod;
        }
        return dp[n][k][val] = ans % mod;
    }
    // Tabulation
    int numOfArraysTab(int n, int m, int k)
    {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));
        for (int l = 0; l <= m; l++)
        {
            dp[0][0][l] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                for (int val = 1; val <= m; val++)
                {
                    if (j > val && k > 0)
                    {
                        ans += dp[n - 1][k - 1][val] % mod;
                    }
                    else if (j <= val)
                        ans += dp[n - 1][k][val - 1] % mod;
                }
            }
        }
        return dp[n][k][m];
    }
    // Space Optimization

    int numOfArrays(int n, int m, int k)
    {
        // return numOfArraysRecur(n, k, 0, m);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return numOfArraysMem(n, k, 0, m, dp);
        // return numOfArraysTab(n, m, k);
    }
};
int main()
{
    Solution s;
    int n = 2, m = 3, k = 1;
    cout << "Max No of ways to create Array: " << s.numOfArrays(n, m, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

Youtube:

algorithm:

*/