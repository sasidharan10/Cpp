#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // TC: O(n)
        // SC: O(1)

        int n = t.size();
        int len = s.size();
        if (len == 0)
            return true;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i] == s[j])
            {
                j++;
                if (j >= len)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    string str = "abc", t = "ahbgdc";
    cout << "Result: " << s.isSubsequence(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/is-subsequence

Youtube:

algorithm:

*/

/*

392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing
the relative positions of the remaining characters.
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/