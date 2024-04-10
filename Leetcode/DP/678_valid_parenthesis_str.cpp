#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    bool checkValidStringRecur(int ind, int open, int n, string s)
    {
        // TC: O(3^n)
        // SC: O(n)

        if (ind == n)
            return (open == 0);
        bool res = false;
        if (s[ind] == '(')
            res |= checkValidStringRecur(ind + 1, open + 1, n, s);
        else if (s[ind] == '*')
        {
            res |= checkValidStringRecur(ind + 1, open + 1, n, s);
            res |= checkValidStringRecur(ind + 1, open, n, s);
            if (open > 0)
                res |= checkValidStringRecur(ind + 1, open - 1, n, s);
        }
        else if (s[ind] == ')' && open > 0)
            res |= checkValidStringRecur(ind + 1, open - 1, n, s);
        return res;
    }
    // Memoization
    bool checkValidStringMem(int ind, int open, int n, string s, vector<vector<int>> &dp)
    {
        // TC: O(n*n)
        // SC: O(n*n) + O(n)

        if (ind == n)
            return (open == 0);
        if (dp[ind][open] != -1)
            return dp[ind][open];
        bool res = false;
        if (s[ind] == '(')
            res |= checkValidStringMem(ind + 1, open + 1, n, s, dp);
        else if (s[ind] == '*')
        {
            res |= checkValidStringMem(ind + 1, open + 1, n, s, dp);
            res |= checkValidStringMem(ind + 1, open, n, s, dp);
            if (open > 0)
                res |= checkValidStringMem(ind + 1, open - 1, n, s, dp);
        }
        else if (s[ind] == ')' && open > 0)
            res |= checkValidStringMem(ind + 1, open - 1, n, s, dp);
        return dp[ind][open] = res;
    }
    // Tabulation
    bool checkValidStringTab(string s)
    {
        // TC: O(n*n)
        // SC: O(n*n)

        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[n][0] = true;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int open = 0; open < n; open++)
            {
                bool res = false;
                if (s[ind] == '(')
                    res |= dp[ind + 1][open + 1];
                else if (s[ind] == '*')
                {
                    res |= dp[ind + 1][open + 1];
                    res |= dp[ind + 1][open];
                    if (open > 0)
                        res |= dp[ind + 1][open - 1];
                }
                else if (s[ind] == ')' && open > 0)
                    res |= dp[ind + 1][open - 1];
                dp[ind][open] = res;
            }
        }
        return dp[0][0];
    }
    // Space Optimization
    bool checkValidStringSpc(string s)
    {
        // TC: O(n*n)
        // SC: O(2n)

        int n = s.length();
        vector<bool> ahead(n + 1);
        ahead[0] = true;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            vector<bool> cur(n + 1);
            for (int open = 0; open < n; open++)
            {
                bool res = false;
                if (s[ind] == '(')
                    res |= ahead[open + 1];
                else if (s[ind] == '*')
                {
                    res |= ahead[open + 1];
                    res |= ahead[open];
                    if (open > 0)
                        res |= ahead[open - 1];
                }
                else if (s[ind] == ')' && open > 0)
                    res |= ahead[open - 1];
                cur[open] = res;
            }
            ahead = cur;
        }
        return ahead[0];
    }

    bool checkValidString(string s)
    {
        int n = s.length();
        // return checkValidStringRecur(0, 0, n, s);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return checkValidStringMem(0, 0, n, s, dp);
        // return checkValidStringTab(s);
        return checkValidStringSpc(s);
    }

    // Using 2 Stacks
    bool checkValidString3(string s)
    {
        // TC: O(n)
        // SC: O(2n)

        int n = s.length();
        stack<int> openSt;
        stack<int> asterixSt;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                openSt.push(i);
            else if (s[i] == '*')
            {
                asterixSt.push(i);
            }
            else
            {
                if (openSt.size() > 0)
                    openSt.pop();
                else if (asterixSt.size() > 0)
                {
                    asterixSt.pop();
                }
                else
                    return false;
            }
        }
        while (!openSt.empty() && !asterixSt.empty())
        {
            if (openSt.top() > asterixSt.top())
                return false;
            openSt.pop();
            asterixSt.pop();
        }
        return openSt.empty();
    }

    // counting open and close brackets
    bool checkValidString2(string s)
    {
        int n = s.length();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*')
                open++;
            else
                open--;
            if (open < 0)
                return false;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
                close++;
            else
                close--;
            if (close < 0)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    string str = "(*))";
    cout << "Result: " << s.checkValidString(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-parenthesis-string/description/

Youtube: https://www.youtube.com/watch?v=Pno2hATcwHA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Valid%20Parenthesis%20String.cpp

algorithm:

- using recursion, dp, tabulation.

- using 2 stacks:
- 1 stack for storing '(' indices, and another for storing '*' indices


- Optimal Approach:

-

*/

/*

678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left
parenthesis '(' or an empty string "".

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true

*/

/*
************* Java Code **************



*/