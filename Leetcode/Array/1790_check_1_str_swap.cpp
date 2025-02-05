#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - using map
    bool areAlmostEqual2(string s1, string s2)
    {
        // TC: O(n)
        // SC: O(26)

        // given, both length same
        int n = s1.length();
        int misMatch = 0;
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            int ch1 = s1[i] - 'a';
            int ch2 = s2[i] - 'a';
            mp[ch1]++;
            mp[ch2]--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] != 0)
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                misMatch++;
        }
        if (misMatch == 0 || misMatch == 2)
            return true;
        else
            return false;
    }

    // Optimal
    bool areAlmostEqual(string s1, string s2)
    {
        // TC: O(n)
        // SC: O(1)

        // given, both length same
        int n = s1.length();
        int misMatch = 0;
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                misMatch++;
                if (misMatch > 2)
                    return false;
                else if (misMatch == 1)
                    firstIndexDiff = i;
                else
                    secondIndexDiff = i;
            }
        }
        return (s1[firstIndexDiff] == s2[secondIndexDiff] && s1[secondIndexDiff] == s2[firstIndexDiff]);
    }
};
int main()
{
    Solution s;
    string s1 = "bank", s2 = "kanb";
    // string s1 = "attack", s2 = "defend";
    cout << "Result: " << s.areAlmostEqual(s1, s2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1790. Check if One String Swap Can Make Strings Equal

You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two
indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly
one of the strings. Otherwise, return false.

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.

*/

/*
************* Java Code **************



*/