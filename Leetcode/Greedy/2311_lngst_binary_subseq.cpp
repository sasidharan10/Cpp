#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int n;

public:
    // Recursion - TLE
    int solveRecur(const string &s, int k, int i)
    {
        // TC: O(2^n)
        // SC: O(1)

        if (i < 0)
            return 0;

        int take = 0;
        int bit = s[i] - '0';
        long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

        if (value <= k)
        {
            take = 1 + solveRecur(s, k - value, i - 1);
        }

        int skip = solveRecur(s, k, i - 1);
        return max(take, skip);
    }

    // Memoization - MLE
    int solveMem(const string &s, int k, int i, vector<vector<int>> &dp)
    {
        if (i < 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int take = 0;
        int bit = s[i] - '0';
        long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

        if (value <= k)
        {
            take = 1 + solveMem(s, k - value, i - 1, dp);
        }

        int skip = solveMem(s, k, i - 1, dp);
        return dp[i][k] = max(take, skip);
    }
    int longestSubsequence2(string s, int k)
    {
        n = s.length();
        // return solveRecur(s, k, n - 1);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solveMem(s, k, n - 1, dp);
    }

    // Greedy
    int longestSubsequence(string s, int k)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.length();
        long long powerVal = 1;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                cnt++;
            else if (powerVal <= k)
            {
                k -= powerVal;
                cnt++;
            }

            if (powerVal <= k)
            {
                powerVal <<= 1;   // powerVal *= 2
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    string str = "1001010";
    int k = 5;
    cout << "Result: " << s.longestSubsequence(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k

Youtube: https://www.youtube.com/watch?v=ca04hcfuGlY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Longest%20Binary%20Subsequence%20Less%20Than%20or%20Equal%20to%20K.cpp

algorithm:

- Optimal Approach:

- You want to pick characters from the string (keeping the order) such that the binary value of the 
  resulting subsequence is ≤ k.
- Start from the end of the string (least significant bit).
- Try to include 0s always (they don’t increase the value).
- Include 1s only if adding them keeps the value ≤ k.

*/

/*

2311. Longest Binary Subsequence Less Than or Equal to K

You are given a binary string s and a positive integer k.
Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without
changing the order of the remaining characters.

Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010",
as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.

Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1,
as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 10^9


*/

/*
************* Java Code **************

    public int longestSubsequence(String s, int k) {
        int n = s.length();
        long powerVal = 1;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0')
                cnt++;
            else if (powerVal <= k) {
                k -= powerVal;
                cnt++;
            }

            if (powerVal <= k) {
                powerVal <<= 1; // powerVal *= 2
            }
        }
        return cnt;
    }

*/