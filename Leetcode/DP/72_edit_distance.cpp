#include <bits/stdc++.h>
using namespace std;
// Recursion
int editDistanceRecur(int i, int j, string word1, string word2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (word1[i] == word2[j])
    {
        return editDistanceRecur(i - 1, j - 1, word1, word2);
    }
    else
    {
        return 1 + min(editDistanceRecur(i, j - 1, word1, word2), min(editDistanceRecur(i - 1, j, word1, word2), editDistanceRecur(i - 1, j - 1, word1, word2)));
    }
}
// Memoization
int editDistanceMem(int i, int j, string word1, string word2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i] == word2[j])
    {
        return dp[i][j] = editDistanceMem(i - 1, j - 1, word1, word2, dp);
    }
    else
    {
        return dp[i][j] = 1 + min(editDistanceMem(i, j - 1, word1, word2, dp), min(editDistanceMem(i - 1, j, word1, word2, dp), editDistanceMem(i - 1, j - 1, word1, word2, dp)));
    }
}
// Tabulation
int editDistanceTab(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
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
            if (word1[i - 1] == word2[j - 1])
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
int editDistanceSpc(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
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
            if (word1[i - 1] == word2[j - 1])
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

int editDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    // return editDistanceRecur(n - 1, m - 1, word1, word2);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return editDistanceMem(n - 1, m - 1, word1, word2, dp);
    return editDistanceTab(word1, word2);
    // return editDistanceSpc(word1, word2);
}
int main()
{
    string word1 = "horse", word2 = "ros";
    cout << "Minimum operations to convert s2 to s1: " << editDistance(word1, word2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/edit-distance_630420

leetcode: https://leetcode.com/problems/edit-distance/

Youtube: https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34

algorithm:

*/