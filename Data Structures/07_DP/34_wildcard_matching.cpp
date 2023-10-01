#include <bits/stdc++.h>
using namespace std;
// Recursion
bool wildcardMatchingRecur(int i, int j, string pattern, string text)
{
    // TC: exponential
    // SC: O(n + m)

    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        while (i >= 0)
        {
            if (pattern[i--] != '*')
                return false;
        }
        return true;
    }
    // matching
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return wildcardMatchingRecur(i - 1, j - 1, pattern, text);
    }
    else if (pattern[i] == '*')
    {
        return wildcardMatchingRecur(i - 1, j, pattern, text) | wildcardMatchingRecur(i, j - 1, pattern, text);
    }
    else
    {
        return false;
    }
}
// Memoization
bool wildcardMatchingMem(int i, int j, string pattern, string text, vector<vector<int>> dp)
{
    // TC: O(n*m)
    // SC: O(n*m) + O(n+m)
    
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    // matching
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = wildcardMatchingMem(i - 1, j - 1, pattern, text, dp);
    }
    else if (pattern[i] == '*')
    {
        return dp[i][j] = wildcardMatchingMem(i - 1, j, pattern, text, dp) | wildcardMatchingMem(i, j - 1, pattern, text, dp);
    }
    else
    {
        return dp[i][j] = false;
    }
}
// Tabulation
bool wildcardMatchingTab(string pattern, string text)
{
    // TC: O(n*m)
    // SC: O(n*m)

    int n = pattern.size();
    int m = text.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
// Space Optimization
bool allStar(string pattern, int i)
{
    for (int k = 1; k <= i; k++)
    {
        if (pattern[k - 1] != '*')
            return false;
    }
    return true;
}
bool wildcardMatchingSpc(string pattern, string text)
{
    // TC: O(n*m)
    // SC: O(m)

    int n = pattern.size();
    int m = text.size();
    vector<bool> prev(m + 1, false), cur(m + 1, false);
    prev[0] = true;
    for (int i = 1; i <= n; i++)
    {
        cur[0] = allStar(pattern, i);
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
            {
                cur[j] = prev[j - 1];
            }
            else if (pattern[i - 1] == '*')
            {
                cur[j] = prev[j] | cur[j - 1];
            }
            else
            {
                cur[j] = false;
            }
        }
        prev = cur;
    }
    return prev[m];
}
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    // return wildcardMatchingRecur(n - 1, m - 1, pattern, text);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return wildcardMatchingMem(n - 1, m - 1, pattern, text, dp);
    // return wildcardMatchingTab(pattern, text);
    return wildcardMatchingSpc(pattern, text);
}
int main()
{
    string pattern = "ab*cd", text = "abdefcd";
    cout << "Pattern match with the text?: " << wildcardMatching(pattern, text);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650

leetcode: https://leetcode.com/problems/wildcard-matching/

Youtube: https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35

algorithm:

*/