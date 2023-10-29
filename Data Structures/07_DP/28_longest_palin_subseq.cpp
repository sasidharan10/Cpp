#include <bits/stdc++.h>
using namespace std;
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
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    // return longestCommonSubsequenceTab(s, t);
    return longestCommonSubsequenceSpc(s, t);
}
int main()
{
    string str = "bbabcbcab";
    cout << "Longest Common Subsequence: " << longestPalindromeSubsequence(str);
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/