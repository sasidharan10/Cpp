#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using stack to store indices.
    string reverseParentheses2(string s)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = s.length();
        string res = "";
        stack<int> st;
        for (int i = 0; i < n; i++) // O(n)
        {
            if (s[i] == '(')
                st.push(res.length());
            else if (s[i] == ')')
            {
                int idx = st.top();
                st.pop();
                reverse(res.begin() + idx, res.end()); // O(n)
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }

    // Optimal - changing directions, when we encounter the parenthesis.
    string reverseParentheses(string s)
    {
        // TC: O(n) + O(n)
        // SC: O(n)
        
        int n = s.length();
        stack<int> openBrackets;
        vector<int> mp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                openBrackets.push(i);
            }
            else if (s[i] == ')')
            {
                int j = openBrackets.top();
                openBrackets.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }
        int flag = 1;
        string res = "";
        for (int i = 0; i < n; i += flag)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = mp[i];
                flag = -flag;
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "(ed(et(oc))el)";
    cout << "Result: " << s.reverseParentheses(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses

Youtube: https://www.youtube.com/watch?v=dUQRS4luBvA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Reverse%20Substrings%20Between%20Each%20Pair%20of%20Parentheses.cpp

algorithm:

- Better Approach:

- We keep start of '(' indices in the stack.
- All characters are pushed into "res" string.
- When we encounter ')', we take the '(' index from stack and reverse it until the end.
- We do this until we reach the last ')'.

- Optimal Approach:

- We append the characters into the "res" string.
- When we encounter the parenthesis, we change the directions.
- Why? lets say str = a(xyz)b
- after modification: azyxb.
- now, str = (a(xyz)b).
- after modification: bxyza.
- So if the substring is encapsulated by 2 parentheses, then we dont need to 
  reverse it.

*/

/*

1190. Reverse Substrings Between Each Pair of Parentheses

You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.

Example 1:

Input: s = "(abcd)"
Output: "dcba"

Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.

*/

/*
************* Java Code **************

    private static void reverseString(StringBuilder str, int start, int end) {
        while (start < end) {
            char temp = str.charAt(start);
            str.setCharAt(start, str.charAt(end));
            str.setCharAt(end, temp);
            start++;
            end--;
        }
    }

    public static String reverseParentheses(String s) {
        int n = s.length();
        StringBuilder res = new StringBuilder();
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
                st.push(res.length());
            else if (s.charAt(i) == ')') {
                int start = st.pop();
                reverseString(res, start, res.length() - 1);
            } else
                res.append(s.charAt(i));
        }
        return res.toString();
    }

    public static String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> openBrackets = new Stack();
        int[] mp = new int[n];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                openBrackets.push(i);
            } else if (s.charAt(i) == ')') {
                int j = openBrackets.peek();
                openBrackets.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }
        int flag = 1;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i += flag) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = mp[i];
                flag = -flag;
            } else
                res.append(s.charAt(i));
        }
        return res.toString();
    }

*/