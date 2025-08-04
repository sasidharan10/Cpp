#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force approach
    bool validPalindrome2(string s)
    {
        // Time Complexity: O(n^2) – For each character (n), we create a new string (O(n)) and check if it's a palindrome (O(n)).
        // Space Complexity: O(n) – New string created on each deletion.

        // If original string is already a palindrome, return true
        if (isPalindrome2(s))
        {
            return true;
        }
        // Try removing each character one by one and check if the new string becomes a palindrome
        for (int i = 0; i < s.size(); i++)
        {
            // Create a new string by skipping character at index i
            string newS = s.substr(0, i) + s.substr(i + 1);

            // Check if the modified string is a palindrome
            if (isPalindrome2(newS))
            {
                return true;
            }
        }
        // If no single deletion leads to a palindrome, return false
        return false;
    }
    // Helper function to check if a given string is a palindrome
    bool isPalindrome2(string s)
    {
        int l = 0, r = s.length() - 1;
        // Use two-pointer approach to check palindrome
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false; // Mismatch found
            }
            l++;
            r--;
        }
        return true; // No mismatches found, it is a palindrome
    }

    // Optimal approach using two pointers
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            // If mismatch found, try skipping either character and check
            if (s[l] != s[r])
            {
                // Try skipping left character OR right character and check if either forms a valid palindrome
                return isPalindrome(s, l + 1, r) || // Skip character at index l
                       isPalindrome(s, l, r - 1);   // Skip character at index r
            }

            // Move both pointers towards the center
            l++;
            r--;
        }
        // If no mismatch found, it's already a palindrome
        return true;
    }

    // Helper function to check if the substring s[l...r] is a palindrome
    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false; // Mismatch found
            }
            l++;
            r--;
        }
        return true; // No mismatches, substring is a palindrome
    }
};
int main()
{
    Solution s;
    string str = "aabaca";
    cout << "Result: " << s.validPalindrome(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-palindrome-ii/

Youtube: https://www.youtube.com/watch?v=JrxRYBwG6EI

Code Link:

algorithm:

- Brute Force Approach:

- Check if original string is a palindrome → if yes, return true.
- Try removing each character one-by-one and check if the resulting string is a palindrome.
- If any such string is a palindrome → return true.
- If none work, return false.

- Optimal Approach:

- Use two pointers (l and r) from both ends.
- If characters match → move inward.
- On first mismatch, try skipping either s[l] or s[r] and check if the remaining substring is a palindrome.
- If either option gives a palindrome → return true.
- If no mismatch or a valid removal found → return true; otherwise, false.

*/

/*

680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.

*/

/*
************* Java Code **************

    public static boolean validPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return isPalindrome(s, l + 1, r) ||
                        isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }

    public static boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

*/