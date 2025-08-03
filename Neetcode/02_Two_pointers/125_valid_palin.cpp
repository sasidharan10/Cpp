#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    bool isPalindrome(string s)
    {
        // TC: O(n)
        // SC: O(n)

        string newStr = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                newStr += tolower(c);
            }
        }
        // reverse(newStr.begin(), newStr.end());
        return newStr == string(newStr.rbegin(), newStr.rend());
    }

    // Optimal - without reversing
    bool isPalindrome(string s)
    {
        // TC: O(n) – each character is processed at most once
        // SC: O(1) – constant space

        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            // Move left pointer to next alphanumeric character
            while (l < r && !alphaNum(s[l]))
            {
                l++;
            }

            // Move right pointer to previous alphanumeric character
            while (r > l && !alphaNum(s[r]))
            {
                r--;
            }

            // Compare characters in a case-insensitive manner
            if (tolower(s[l]) != tolower(s[r]))
            {
                return false; // mismatch → not a palindrome
            }

            l++;
            r--;
        }
        return true; // all characters matched
    }

    // Helper function to check if a character is alphanumeric
    bool alphaNum(char c)
    {
        return (c >= 'A' && c <= 'Z' || // uppercase
                c >= 'a' && c <= 'z' || // lowercase
                c >= '0' && c <= '9');  // digit
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-palindrome/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.


*/

/*
************* Java Code **************

    public boolean isPalindrome(String s) {
        StringBuilder newStr = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                newStr.append(Character.toLowerCase(c));
            }
        }
        return newStr.toString().equals(newStr.reverse().toString());
    }

*/