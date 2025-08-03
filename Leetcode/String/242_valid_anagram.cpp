#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    bool isAnagram2(string s, string t)
    {
        // TC: O(NlogN) – due to sorting
        // SC: O(1) – assuming character set size is fixed (only lowercase letters)

        int n = s.length();
        int m = t.length();

        if (n != m)
            return false; // if lengths differ, they can't be anagrams

        sort(s.begin(), s.end()); // sort both strings
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
                return false; // if any character doesn't match, not an anagram
        }

        return true; // all characters match in sorted order
    }

    // Optimal
    bool isAnagram(string s, string t)
    {
        // TC: O(N) – single pass through strings + O(26) to check counts
        // SC: O(26) – fixed-size frequency array

        int n = s.length();
        int m = t.length();

        if (n != m)
            return false; // different lengths can't be anagrams

        vector<int> mp(26, 0); // frequency map for 26 lowercase letters

        for (int i = 0; i < n; i++)
        {
            int ch1 = s[i] - 'a'; // index for character in s
            int ch2 = t[i] - 'a'; // index for character in t
            mp[ch1]++;            // increment count for s
            mp[ch2]--;            // decrement count for t
        }

        for (auto it : mp)
        {
            if (it != 0)
                return false; // mismatch in frequencies → not an anagram
        }
        return true; // all frequencies matched → valid anagram
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

- Brute force Approach

- Check if length of both string are equal.
- Sort both string, then traverse on both strings, and
  check if s[i] == t[i].

- Optimal Approach

- Given the string contain only lowercase alphabets, hence we can use
  mp[26], and store frequency of every character in string "s" and "t"
  then check if all characters are present, if yes, check if its
  frequency is same.

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

/*
************* Java Code **************

    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();

        if (n != m)
            return false; // different lengths can't be anagrams

        int[] mp = new int[26]; // frequency map for 26 lowercase letters

        for (int i = 0; i < n; i++) {
            int ch1 = s.charAt(i) - 'a'; // index for character in s
            int ch2 = t.charAt(i) - 'a'; // index for character in t
            mp[ch1]++; // increment count for s
            mp[ch2]--; // decrement count for t
        }

        for (int count : mp) {
            if (count != 0)
                return false; // mismatch in frequencies → not an anagram
        }
        return true; // all frequencies matched → valid anagram
    }

*/