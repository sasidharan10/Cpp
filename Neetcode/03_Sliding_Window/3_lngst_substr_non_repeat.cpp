#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int lengthOfLongestSubstring2(string s)
    {
        // TC: O(n^2)
        // SC: O(255) ~ O(1)

        int n = s.length();
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> mp(255, -1);
            for (int j = i; j < n; j++)
            {
                int idx = s[j];
                if (mp[idx] != -1)
                    break;
                mp[idx] = 1;
                int len = j - i + 1;
                maxi = max(len, maxi);
            }
        }
        return maxi;
    }

    // Optimal - sliding window
    int lengthOfLongestSubstring(string s)
    {
        // TC: O(n)
        // SC: O(255) ~ O(1)

        int n = s.length();
        int maxi = 0;
        vector<int> mp(255, -1);
        int l = 0, r = 0;
        while (r < n)
        {
            int idx = s[r];
            if (mp[idx] >= l)
            {
                l = mp[idx] + 1;
            }
            else
            {
                int len = r - l + 1;
                maxi = max(len, maxi);
                mp[idx] = r;
                r++;
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << "Result: " << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Youtube: https://www.youtube.com/watch?v=-zSxTJkcdAo

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/

/*
************* Java Code **************

    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxi = 0;
        int[] mp = new int[255];
        Arrays.fill(mp, -1);
        int l = 0, r = 0;
        while (r < n) {
            int idx = s.charAt(r);
            if (mp[idx] >= l) {
                l = mp[idx] + 1;
            } else {
                int len = r - l + 1;
                maxi = Math.max(len, maxi);
                mp[idx] = r;
                r++;
            }
        }
        return maxi;
    }

*/