#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int scoreOfString(string s)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.length();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans += abs(s[i - 1] - s[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "hello";
    cout << "Result: " << s.scoreOfString(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/score-of-a-string/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

3110. Score of a String

You are given a string s. The score of a string is defined as the sum of the absolute
difference between the ASCII values of adjacent characters.

Return the score of s.

Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111.
So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s
would be |122 - 97| + |97 - 122| = 25 + 25 = 50.


Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.

*/

/*
************* Java Code **************

public int scoreOfString(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans += Math.abs(s.charAt(i - 1) - s.charAt(i));
        }
        return ans;
    }

*/