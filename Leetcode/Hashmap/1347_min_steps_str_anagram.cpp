#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSteps(string s, string t)
    {
        // TC: O(n)
        // SC: O(26) ~ O(1)
        
        // vector<int> mp(26, 0);
        int mp[26];
        memset(mp, 0, sizeof(mp));
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }
        int cnt = 0;
        for (int it : mp)
        {
            if (it < 0)
            {
                cnt += -(it);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    string str = "leetcode", t = "practice";
    cout << "Minimum Number of Steps to Make Two Strings Anagram: ";
    cout << s.minSteps(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

Youtube:

algorithm:

*/

/*

1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can
choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with
a different (or the same) ordering.

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with
proper characters to make t anagram of s.

Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.

*/