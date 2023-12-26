#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int numDecodingsRecur(int ind, int n, string &s)
    {
        // TC: O(2^n)
        // SC: 
        
        if (ind == n)
            return 1;

        if (s[ind] == '0')
            return 0;
        int res = 0;
        // taking 1 character
        res = numDecodingsRecur(ind + 1, n, s);
        // taking 2 character2
        if (ind + 1 < n && s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')
            res += numDecodingsRecur(ind + 2, n, s);
        return res;
    }
    // Memoization
    int numDecodingsMem(int ind, int n, string &s, vector<int> &dp)
    {
        // TC: O(n) + O(n) stack space
        // SC: O(n) or O(101) ~ O(1)
        
        if (dp[ind] != -1)
            return dp[ind];
        if (ind == n)
            return dp[ind] = 1;

        if (s[ind] == '0')
            return dp[ind] = 0;
        int res = 0;
        // taking 1 character
        res = numDecodingsMem(ind + 1, n, s, dp);
        // taking 2 character2
        if (ind + 1 < n)
        {
            if (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')
                res += numDecodingsMem(ind + 2, n, s, dp);
        }
        return dp[ind] = res;
    }
    // Tabulation
    int numDecodingsTab(string s)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            if (s[ind] == '0')
            {
                dp[ind] = 0;
                continue;
            }
            int res = 0;
            // taking 1 character
            res = dp[ind + 1];
            // taking 2 character2
            if (ind + 1 < n)
            {
                if (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')
                    res += dp[ind + 2];
            }
            dp[ind] = res;
        }
        return dp[0];
    }
    // Space Optimization
    int numDecodingsSpc(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int cur = 0, prev1, prev2 = 0;
        prev1 = 1;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            if (s[ind] == '0')
                cur = 0;
            else
            {
                // taking 1 character
                cur = prev1;
                // taking 2 character2
                if (ind + 1 < n)
                {
                    if (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')
                        cur += prev2;
                }
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int numDecodings(string s)
    {
        int n = s.length();
        // return numDecodingsRecur(0, n, s);
        vector<int> dp(n + 1, -1);
        // return numDecodingsMem(0, n, s, dp);
        // return numDecodingsTab(s);
        return numDecodingsSpc(s);
    }
};
int main()
{
    Solution s;
    // string str = "11106";
    string str = "226";
    cout << "No of Ways to Decode given String: " << s.numDecodings(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/decode-ways

Youtube: https://www.youtube.com/watch?v=HW-y3gvQTVQ

algorithm:

*/

/*

91. Decode Ways

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped
back into letters using the reverse of the mapping above (there may be multiple ways).
For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be
mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading
zero ("6" is different from "06").




*/