#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkPalindrome(string s)
    {
        int n = s.length();
        if (n != 5)
            return false;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        // cout << "Str: " << s << endl;
        return true;
    }
    // Recursion
    int countPalindromesRecur(int ind, int n, string temp, string s)
    {
        if (ind == n)
        {
            return checkPalindrome(temp) ? 1 : 0;
        }
        int notPick = countPalindromesRecur(ind + 1, n, temp, s);
        int pick = countPalindromesRecur(ind + 1, n, temp + s[ind], s);
        return pick + notPick;
    }
    // Memoization
    int countPalindromesMem(int ind, int n, string temp, string s, unordered_map<string, int> &mp)
    {
        if (ind == n)
        {
            return checkPalindrome(temp) ? 1 : 0;
        }
        string idx = to_string(ind) + "_" + temp;
        if (mp.find(idx) != mp.end())
            return mp[idx];
        int notPick = countPalindromesMem(ind + 1, n, temp, s, mp);
        int pick = countPalindromesMem(ind + 1, n, temp + s[ind], s, mp);
        return mp[idx] = pick + notPick;
    }
    // Tabulation

    // Space Optimization

    int countPalindromes(string s)
    {
        int n = s.length();
        unordered_map<string, int> mp;
        // return countPalindromesRecur(0, n, "", s, mp);
        return countPalindromesMem(0, n, "", s, mp);
    }
};
int main()
{
    Solution s;
    string str = "103301";
    cout << "Result: " << s.countPalindromes(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-palindromic-subsequences/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

2484. Count Palindromic Subsequences

Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since
the answer may be very large, return it modulo 109 + 7.

Note:

A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no characters without
changing the order of the remaining characters.

Example 1:

Input: s = "103301"
Output: 2
Explanation:
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301".
Two of them (both equal to "10301") are palindromic.

Example 2:

Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:

Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".

Constraints:

1 <= s.length <= 10^4
s consists of digits.

*/

/*
************* Java Code **************



*/