#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // TC: O(n + m)
        // SC: O(n)
        
        int n = s.length();
        int m = t.length();
        if (m > n)
            return "";
        int mini = INT_MAX;
        int start = 0;
        int requiredCnt = m;
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[t[i]]++;
        }
        int i = 0, j = 0;
        while (j < n)
        {
            // is required
            if (mp[s[j]] > 0)
            {
                requiredCnt--;
            }

            mp[s[j]]--;
            // we have all required chars in the current window, hence time to shrink the window
            while (requiredCnt == 0)
            {
                int curWindowSize = j - i + 1;
                if (curWindowSize < mini)
                {
                    mini = curWindowSize;
                    start = i;
                }
                mp[s[i]]++;
                // if true, it means we lost 1 char from the current window
                if (mp[s[i]] > 0)
                {
                    requiredCnt++;
                }
                i++;
            }
            j++;
        }
        if (mini == INT_MAX)
            return "";
        else
            return s.substr(start, mini);
        return "";
    }
};
int main()
{
    Solution s;
    string str = "ADOBECODEBANC", t = "ABC";
    cout << "Result: " << s.minWindow(str, t) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-window-substring

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in
 the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/