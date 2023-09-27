#include <bits/stdc++.h>
using namespace std;
// Recursion
int longestCommonSubsequenceRecur(int ind1, int ind2, string text1, string text2)
{

    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (text1[ind1] == text2[ind2])
        return 1 + longestCommonSubsequenceRecur(ind1 - 1, ind2 - 1, text1, text2);
    else
        return max(longestCommonSubsequenceRecur(ind1 - 1, ind2, text1, text2), longestCommonSubsequenceRecur(ind1, ind2 - 1, text1, text2));
}
// Memoization
int longestCommonSubsequenceMem(int ind1, int ind2, string text1, string text2, vector<vector<int>> &dp)
{
    // TC: O(2^n) + O(2^m) >> exponential
    // SC: O(n+m)

    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (text1[ind1] == text2[ind2])
        return dp[ind1][ind2] = 1 + longestCommonSubsequenceMem(ind1 - 1, ind2 - 1, text1, text2, dp);
    else
        return dp[ind1][ind2] = max(longestCommonSubsequenceMem(ind1 - 1, ind2, text1, text2, dp), longestCommonSubsequenceMem(ind1, ind2 - 1, text1, text2, dp));
}
// Tabulation
int longestCommonSubsequenceTab(string text1, string text2)
{
    // TC: O(n*m)
    // SC: O(n*m)

    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
// Space Optimization
int longestCommonSubsequenceSpc(string text1, string text2)
{
    // TC: O(n*m)
    // SC: O(m)

    int n = text1.length();
    int m = text2.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 0; j <= m; j++)
    {
        prev[j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

int longestCommonSubsequence(string text1, string text2)
{
    // return longestCommonSubsequenceRecur(text1.length() - 1, text2.length() - 1, text1, text2);
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return longestCommonSubsequenceMem(n - 1, m - 1, text1, text2, dp);
    // return longestCommonSubsequenceTab(text1, text2);
    return longestCommonSubsequenceSpc(text1, text2);
}
int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << "Longest Common Subsequence: " << longestCommonSubsequence(text1, text2);
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/