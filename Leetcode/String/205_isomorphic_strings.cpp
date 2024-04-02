#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // TC: O(n)
        // SC: O(n)

        int n = s.length();
        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1))
                return false;

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};
int main()
{
    Solution s;
    // string str = "egg", t = "add";
    // string str = "foo", t = "bar";
    // string str = "bbbaaaba", t = "aaabbbba";
    string str = "badc", t = "baba";
    cout << "Result: " << s.isIsomorphic(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/isomorphic-strings/
 
Youtube: https://www.youtube.com/watch?v=2ISNCDJEgqQ

Code Link:

algorithm:

- 

*/

/*

205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same character,
but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

*/

/*
************* Java Code **************

public static boolean isIsomorphic(String s, String t) {
        int n = s.length();
        HashMap<Character, Character> mp1 = new HashMap<>();
        HashMap<Character, Character> mp2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);

            if ((mp1.containsKey(ch1) && mp1.get(ch1) != ch2) || (mp2.containsKey(ch2) && mp2.get(ch2) != ch1))
                return false;

            mp1.put(ch1, ch2);
            mp2.put(ch2, ch1);
        }
        return true;
    }

*/