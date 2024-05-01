#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int longestIdealStringRecur(int ind, int prev, int n, string s, int k)
    {
        if (ind == n)
            return 0;
        int pick = INT_MIN;
        if (prev == -1 || abs(s[prev] - s[ind] <= k))
            pick = 1 + longestIdealStringRecur(ind + 1, ind, n, s, k);
        int notPick = longestIdealStringRecur(ind + 1, prev, n, s, k);
        return max(pick, notPick);
    }
    // Memoization
    int longestIdealStringMem(int ind, int prev, int n, string s, int k, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        int pick = INT_MIN;
        int cur = s[ind] - 'a';
        if (prev == -1 || abs(prev - cur) <= k)
            pick = 1 + longestIdealStringMem(ind + 1, cur, n, s, k, dp);
        int notPick = longestIdealStringMem(ind + 1, prev, n, s, k, dp);
        return dp[ind][prev + 1] = max(pick, notPick);
    }
    // Tabulation

    // Space Optimization

    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        // return longestIdealStringRecur(0, -1, n, s, k);
        return longestIdealStringMem(0, -1, n, s, k, dp);
    }
};
int main()
{
    Solution s;
    // string str = "acfgbd";
    // int k = 2;
    string str = "abcd";
    int k = 3;
    cout << "Result: " << s.longestIdealString(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-ideal-subsequence/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2370. Longest Ideal Subsequence

You are given a string s consisting of lowercase letters and an integer k. We call
a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t
is less than or equal to k. Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting
some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference
in the alphabet order of 'a' and 'z' is 25, not 1.

Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.

Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.

*/

/*
************* Java Code **************



*/