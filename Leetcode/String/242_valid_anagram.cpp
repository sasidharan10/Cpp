#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram2(string s, string t)
    {
        // TC: O(NlogN)
        // SC: O(1)

        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t)
    {
        // TC: O(N) + O(26)
        // SC: O(26)

        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            int ch1 = s[i] - 'a';
            int ch2 = t[i] - 'a';
            mp[ch1]++;
            mp[ch2]--;
        }
        for (auto it : mp)
        {
            if (it != 0)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    string str = "anagram", t = "nagaram";
    cout << "Is Anagram: " << s.isAnagram(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-anagram

Youtube:

algorithm:

*/

/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/