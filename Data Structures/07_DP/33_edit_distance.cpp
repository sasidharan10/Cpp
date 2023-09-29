#include <bits/stdc++.h>
using namespace std;
// Recursion
int editDistanceRecur(int i, int j, string str1, string str2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (str1[i] == str2[j])
    {
        return editDistanceRecur(i - 1, j - 1, str1, str2);
    }
    else
    {
        return 1 + min(editDistanceRecur(i, j - 1, str1, str2), min(editDistanceRecur(i - 1, j, str1, str2), editDistanceRecur(i - 1, j - 1, str1, str2)));
    }
}
// Memoization
int editDistanceMem(int i, int j, string str1, string str2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i] == str2[j])
    {
        return dp[i][j] = editDistanceMem(i - 1, j - 1, str1, str2, dp);
    }
    else
    {
        return dp[i][j] = 1 + min(editDistanceMem(i, j - 1, str1, str2, dp), min(editDistanceMem(i - 1, j, str1, str2, dp), editDistanceMem(i - 1, j - 1, str1, str2, dp)));
    }
}
// Tabulation
int editDistanceTab(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}
// Space Optimization
int editDistanceSpc(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                cur[j] = prev[j - 1];
            }
            else
            {
                cur[j] = 1 + min(cur[j - 1], min(prev[j], prev[j - 1]));
            }
        }
        prev = cur;
    }
    return prev[m];
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // return editDistanceRecur(n - 1, m - 1, str1, str2);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return editDistanceMem(n - 1, m - 1, str1, str2, dp);
    return editDistanceTab(str1, str2);
    // return editDistanceSpc(str1, str2);
}
int main()
{
    string s1 = "whgtdwhgtdg", s2 = "aswcfg";
    cout << "Shortest common Supersequence: " << editDistance(s1, s2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/edit-distance_630420

leetcode:

Youtube: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34

algorithm:

*/