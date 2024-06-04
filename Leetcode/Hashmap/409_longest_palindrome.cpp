#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using set and pairing the characters
    int longestPalindrome2(string s)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = s.length();
        unordered_set<char> st;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.find(s[i]) != st.end())
            {
                res += 2;
                st.erase(s[i]);
            }
            else
                st.insert(s[i]);
        }
        if (!st.empty())
            res++;
        return res;
    }

    // Using map
    int longestPalindrome(string s)
    {
        // TC: O(n) + O(128)
        // SC: O(128) ~ O(1)

        int n = s.length();
        vector<int> mp(128, 0);
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'A']++;
        }
        bool oddCount = true;
        int res = 0;
        for (int it : mp)
        {
            if (it == 0)
                continue;
            else if (it % 2 == 0)
                res += it;
            else
            {
                if (oddCount)
                {
                    res += it;
                    oddCount = false;
                }
                else if (it > 2)
                    res += (it - 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "abccccdd";
    cout << "Result: " << s.longestPalindrome(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-palindrome/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- using map and checking the character's count.

*/

/*

409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest
palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

*/

/*
************* Java Code **************

public int longestPalindrome(String s) {
        int n = s.length();
        int[] mp = new int[128];
        for (int i = 0; i < n; i++) {
            mp[s.charAt(i) - 'A']++;
        }
        boolean oddCount = true;
        int res = 0;
        for (int it : mp) {
            if (it == 0)
                continue;
            else if (it % 2 == 0)
                res += it;
            else {
                if (oddCount) {
                    res += it;
                    oddCount = false;
                } else if (it > 2)
                    res += (it - 1);
            }
        }
        return res;
    }

*/