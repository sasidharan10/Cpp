#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    bool isMatchRecur(int i, int j, string p, string s)
    {
        // TC: exponential
        // SC: O(n + m)

        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        // matching
        if (p[i] == s[j] || p[i] == '?')
        {
            return isMatchRecur(i - 1, j - 1, p, s);
        }
        else if (p[i] == '*')
        {
            return isMatchRecur(i - 1, j, p, s) | isMatchRecur(i, j - 1, p, s);
        }
        else
        {
            return false;
        }
    }
    // Memoization
    bool isMatchMem(int i, int j, string p, string s, vector<vector<int>> &dp)
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
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        // matching
        if (p[i] == s[j] || p[i] == '?')
        {
            return dp[i][j] = isMatchMem(i - 1, j - 1, p, s, dp);
        }
        else if (p[i] == '*')
        {
            return dp[i][j] = isMatchMem(i - 1, j, p, s, dp) | isMatchMem(i, j - 1, p, s, dp);
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    // Tabulation
    bool isMatchTab(string p, string s)
    {
        // TC: O(n*m)
        // SC: O(n*m)

        int n = p.size();
        int m = s.size();
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
                if (p[k - 1] != '*')
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
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
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
    bool isMatchSpc(string p, string s)
    {
        // TC: O(n*m)
        // SC: O(m)

        int n = p.size();
        int m = s.size();
        vector<bool> prev(m + 1, false), cur(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++)
        {
            cur[0] = allStar(p, i);
            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    cur[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*')
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

    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        // return isMatchRecur(n - 1, m - 1, p, s);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return isMatchMem(n - 1, m - 1, p, s, dp);
        // return isMatchTab(p, s);
        return isMatchSpc(p, s);
    }
};
int main()
{
    Solution s;
    string pattern = "ab*cd", text = "abdefcd";
    cout << "Pattern match with the text?: " << s.isMatch(text, pattern);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/wildcard-matching/

Youtube: https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35

algorithm:

*/