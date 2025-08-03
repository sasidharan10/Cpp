#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int characterReplacement3(string s, int k)
    {
        // TC: O(n^2)
        // SC: O(26)

        int n = s.length();
        int maxLen = 0;

        // Try every possible substring starting from index i
        for (int i = 0; i < n; i++)
        {
            int maxFreq = 0;

            for (int j = i; j < n; j++)
            {
                vector<int> mp(26, 0); // frequency map for current window

                // Update frequency of current character
                int idx = s[j] - 'A';
                mp[idx]++;

                // Update max frequency in current substring
                maxFreq = max(maxFreq, mp[idx]);

                // Calculate how many characters need to be changed
                int changes = (j - i + 1) - maxFreq;

                // If within allowed changes, update maxLen
                if (changes <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break; // can't make more than k changes, break early
            }
        }
        return maxLen;
    }

    // Better - sliding window
    int characterReplacement2(string s, int k)
    {
        // TC: O(2n) * 26 — maxFreq is recalculated inside the loop
        // SC: O(26)

        int n = s.length();
        int maxLen = 0, maxFreq = 0;
        int l = 0, r = 0;
        vector<int> mp(26, 0); // frequency map

        while (r < n)
        {
            int idx = s[r] - 'A';
            mp[idx]++;                       // add current character to window
            maxFreq = max(maxFreq, mp[idx]); // update most frequent character count

            // If window needs more than k changes, shrink from left
            while ((r - l + 1) - maxFreq > k)
            {
                mp[s[l] - 'A']--; // remove character at left
                // Recalculate maxFreq (costly step)
                maxFreq = 0;
                for (int i = 0; i < 26; i++)
                {
                    maxFreq = max(maxFreq, mp[i]);
                }
                l++;
            }

            // Update maxLen if current window is valid
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }

    // Optimal - sliding window
    int characterReplacement(string s, int k)
    {
        // TC: O(2n) — maxFreq is never recalculated
        // SC: O(26)

        int n = s.length();
        int maxLen = 0, maxFreq = 0;
        int l = 0, r = 0;
        vector<int> mp(26, 0); // frequency map

        while (r < n)
        {
            mp[s[r] - 'A']++; // include current character in the window

            // Track max frequency character in window
            maxFreq = max(maxFreq, mp[s[r] - 'A']);

            // If changes needed exceed k, shrink window from left
            if ((r - l + 1) - maxFreq > k)
            {
                mp[s[l] - 'A']--; // remove leftmost character
                l++;
            }

            // If window is valid (changes ≤ k), update maxLen
            if ((r - l + 1) - maxFreq <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++; // expand window to the right
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    string str = "AABABBA";
    int k = 1;
    cout << "Result: " << s.characterReplacement(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-repeating-character-replacement/

Youtube: https://www.youtube.com/watch?v=_eNhaDCr6P0

Code Link:

algorithm:

- Brute Force Approach:

- For each i, extend the substring to j and:
- Track frequency of each character using a fresh map for each (i, j).
- Keep count of the most frequent character (maxFreq) in the current window.
- Compute how many characters need replacement: window size - maxFreq.
- If replacements needed ≤ k, update max length.
- If replacements exceed k, stop expanding that window.

- Better Approach:

- Use a sliding window (l, r) to avoid checking all substrings.
- Keep a running frequency map of characters in the current window.
- Track maxFreq of any character in the window.
- If replacements needed (window size - maxFreq) > k, shrink the window from the left.
- Key Difference: maxFreq is recalculated after shrinking (costly loop over 26 characters).

Optimal Approach:

- Same as the sliding window idea, but with an optimization:
- maxFreq is never recalculated when shrinking the window.
- We rely on the fact that even if maxFreq is slightly outdated, the window will still adjust correctly.
- Shrink window only when replacements needed > k.
- Always expand window to the right and keep updating max length.

*/

/*

424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any
other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Constraints:

1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length


*/

/*
************* Java Code **************

    public int characterReplacement(String s, int k) {
        int n = s.length();
        int maxLen = 0, maxFreq = 0;
        int l = 0, r = 0;
        int[] mp = new int[26]; // frequency map

        while (r < n) {
            mp[s.charAt(r) - 'A']++; // include current character in the window

            // Track max frequency character in window
            maxFreq = Math.max(maxFreq, mp[s.charAt(r) - 'A']);

            // If changes needed exceed k, shrink window from left
            if ((r - l + 1) - maxFreq > k) {
                mp[s.charAt(l) - 'A']--; // remove leftmost character
                l++;
            }

            // If window is valid (changes ≤ k), update maxLen
            if ((r - l + 1) - maxFreq <= k) {
                maxLen = Math.max(maxLen, r - l + 1);
            }
            r++; // expand window to the right
        }
        return maxLen;
    }

*/