#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using stack
    int minAddToMakeValid2(string s)
    {
        // TC: O(n)
        // SC: O(n)

        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && s[i] == ')' && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
    
    // Optimal - without stack
    int minAddToMakeValid(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (s[i] == ')' && open > 0)
            {
                open--;
                close--;
            }
        }
        return open + close;
    }
};
int main()
{
    Solution s;
    string str = "()))";
    cout << "Result: " << s.minAddToMakeValid(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

Youtube:

Code Link:

algorithm:

- Better Approach:

- Using stack

- Optimal Approach:

- without stack, code is self explanatory.

*/

/*

921. Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position
of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing
parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.

*/

/*
************* Java Code **************

    public int minAddToMakeValid(String s) {
        int n = s.length();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == '(')
                open++;
            else
                close++;

            if (s.charAt(i) == ')' && open > 0)
            {
                open--;
                close--;
            }
        }
        return open + close;
    }

*/