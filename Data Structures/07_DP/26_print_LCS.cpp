#include <bits/stdc++.h>
using namespace std;
// Tabulation
string longestCommonSubsequenceTab(string text1, string text2)
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
    int l = dp[n][m];
    string res = "";
    for (int i = 0; i < l; i++)
    {
        res += "$";
    }
    l--;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            res[l] = text1[i - 1];
            l--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }
    return res;
}
string longestCommonSubsequence(string text1, string text2)
{
    // return longestCommonSubsequenceRecur(text1.length() - 1, text2.length() - 1, text1, text2);
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return longestCommonSubsequenceMem(n - 1, m - 1, text1, text2, dp);
    return longestCommonSubsequenceTab(text1, text2);
}
int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << "Longest Common Subsequence: " << longestCommonSubsequence(text1, text2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?leftPanelTab=1

leetcode: 

Youtube: https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27

algorithm: 

*/