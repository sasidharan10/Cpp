#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string rotateStr(string str)
    {
        int n = str.length();
        return str.substr(1, n - 1) + str[0];
    }
    // Brute force
    bool rotateString2(string s, string goal)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = s.length();
        int m = goal.length();
        if (n != m)
            return false;
        string temp = s;
        for (int i = 0; i < n; i++)
        {
            temp = rotateStr(temp);
            if (temp == goal)
                return true;
        }
        return false;
    }

    // Better - Using string concatenation and finding the target in it.
    bool rotateString(string s, string goal)
    {
        // TC: O(nlogn) + O(mlogm)
        // SC: O(1)

        int n = s.length();
        int m = goal.length();
        if (n != m)
            return false;
        string temp = s + s;
        if (temp.find(goal) != string::npos)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    string str = "abcde", goal = "cdeab";
    // string str = "abcde", goal = "abced";
    cout << "Result: " << s.rotateString2(str, goal) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/rotate-string

Youtube: https://www.youtube.com/watch?v=6fFWixNh4rg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Easy%20Tagged/Rotate%20String.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

796. Rotate String

Given two strings s and goal, return true if and only if s can become goal after some
number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:

Input: s = "abcde", goal = "abced"
Output: false

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

*/

/*
************* Java Code **************

    public boolean rotateString(String s, String goal) {
        int m = s.length();
        int n = goal.length();

        // Check if the lengths match and if goal is a substring of s + s
        if (m == n && (s + s).contains(goal)) {
            return true;
        }

        return false;
    }

*/