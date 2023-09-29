#include <bits/stdc++.h>
using namespace std;
// Recursion
int distinctSubsequencesRecur(int i, int j, string &str, string &sub)
{
    // TC: O(2^n) + O(2^m)  >> hence, exponential
    // SC: O(n + m)

    if (i < 0)
        return 0;
    if (j < 0)
        return 1;
    if (str[i] == sub[j])
    {
        return distinctSubsequencesRecur(i - 1, j - 1, str, sub) + distinctSubsequencesRecur(i - 1, j, str, sub);
    }
    else
    {
        return distinctSubsequencesRecur(i - 1, j, str, sub);
    }
}
// Memoization
int distinctSubsequencesMem(int i, int j, string &str, string &sub, vector<vector<int>> &dp)
{
    // TC: O(n*m)
    // SC: O(n*m) + O(n + m)

    if (i < 0)
        return 0;
    if (j < 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str[i] == sub[j])
    {
        return dp[i][j] = distinctSubsequencesMem(i - 1, j - 1, str, sub, dp) + distinctSubsequencesMem(i - 1, j, str, sub, dp);
    }
    else
    {
        return dp[i][j] = distinctSubsequencesMem(i - 1, j, str, sub, dp);
    }
}
// Tabulation
int distinctSubsequencesTab(string &str, string &sub)
{
    int mod = 1e9 + 7;
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    // 0s already assigned for dp[0][j]
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j])%mod;
            }
        }
    }
    return dp[n][m];
}
// Space Optimization
int distinctSubsequencesSpc(string &str, string &sub)
{
    int mod = 1e9 + 7;
    int n = str.size();
    int m = sub.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    prev[0] = 1;
    cur[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                cur[j] = (prev[j - 1] + prev[j]) % mod;
            }
            else
            {
                cur[j] = (prev[j]) % mod;
            }
        }
        prev = cur;
    }
    return prev[m];
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    // return distinctSubsequencesRecur(n - 1, m - 1, str, sub);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return distinctSubsequencesMem(n - 1, m - 1, str, sub, dp);
    // return distinctSubsequencesTab(str, sub);
    return distinctSubsequencesSpc(str, sub);
}
int main()
{
    string s1 = "dingdingdingding", s2 = "ing";
    cout << "Shortest common Supersequence: " << distinctSubsequences(s1, s2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/subsequence-counting_3755256

leetcode:

Youtube: https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=33

algorithm:

*/