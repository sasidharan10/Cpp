#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
                cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    string str = "(1+(2*3)+((8)/4))+1";
    cout << "Max Depth of Parenthesis: " << s.maxDepth(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Youtube: https://www.youtube.com/watch?v=uzP77oJVLos

Code Link:

algorithm:

- Count the depth of parenthesis, like () = 1, (()) = 2, ((())) = 3, etc.
- increase cnt when we encounter '(' and decrement when we encounter ')'.
- Update maxi, after every iteration.

*/

/*

1614. Maximum Nesting Depth of the Parentheses

A string is a valid parentheses string (denoted VPS) if it meets one of the following:

It is an empty string "", or a single character not equal to "(" or ")",
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), 
and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3

*/

/*
************* Java Code **************

public int maxDepth(String s) {
        int n = s.length();
        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
                cnt++;
            else if (s.charAt(i) == ')')
                cnt--;
            maxi = Math.max(maxi, cnt);
        }
        return maxi;
    }

*/