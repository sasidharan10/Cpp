#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string str)
    {
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};
int main()
{
    Solution s;
    vector<string> words = {"abc", "car", "ada", "racecar", "cool"};
    cout << "First Palindromic String: " << s.firstPalindrome(words) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-first-palindromic-string-in-the-array

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2108. Find First Palindromic String in the Array

Given an array of strings words, return the first palindromic string 
in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

*/