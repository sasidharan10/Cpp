#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        // TC: O(n + m)
        // SC: O(1)

        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (j == m)
            return 0;
        else
            return m - j;
    }
};
int main()
{
    Solution s;
    string str = "coaching", t = "coding";
    cout << "Result: " << s.appendCharacters(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- using 2 pointer approach.
- Find the longest subseq in 's', by iterating using 2 pointers.
- If we find all all letters present in s, then return 0, else return the remaining
  letters in 't' which is not found in 's'.

*/

/*

2486. Append Characters to String to Make Subsequence

You are given two strings s and t consisting of only lowercase English letters.
Return the minimum number of characters that need to be appended to the end of s so
that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or
no characters without changing the order of the remaining characters.

Example 1:

Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.

Example 2:

Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").

Example 3:

Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.

Constraints:

1 <= s.length, t.length <= 105
s and t consist only of lowercase English letters.

*/

/*
************* Java Code **************

public int appendCharacters(String s, String t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s.charAt(i) == t.charAt(j))
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (j == m)
            return 0;
        else
            return m - j;
    }

*/