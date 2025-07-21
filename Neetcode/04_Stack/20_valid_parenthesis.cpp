#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // optimal
    bool isValid2(string s)
    {
        // TC: O(n)
        // SC: O(n)

        int n = s.length();
        if (n % 2 != 0)
            return false;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (!st.empty() && st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (!st.empty() && st.top() == '[' && s[i] == ']')
                    st.pop();
                else if (!st.empty() && st.top() == '{' && s[i] == '}')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }

    // cleaner code
    bool isValid(string s)
    {
        // TC: O(n)
        // SC: O(n)

        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s)
        {
            if (mapping.find(c) == mapping.end())
            {
                stack.push(c);
            }
            else if (!stack.empty() && mapping[c] == stack.top())
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        return stack.empty();
    }
};
int main()
{
    Solution s;
    string str = "()[]{}";
    cout << "Result: " << s.isValid(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-parentheses

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- use stack

*/

/*

20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([])"
Output: true

Example 5:

Input: s = "([)]"
Output: false

Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.

*/

/*
************* Java Code **************

    public boolean isValid(String s) {
        int n = s.length();
        if (n % 2 != 0)
            return false;
        Stack<Character> st = new Stack<>();
        char[] charArray = s.toCharArray();
        for (int i = 0; i < n; i++) {
            if (charArray[i] == '(' || charArray[i] == '[' || charArray[i] == '{')
                st.push(charArray[i]);
            else {
                if (!st.isEmpty() && st.peek() == '(' && charArray[i] == ')')
                    st.pop();
                else if (!st.isEmpty() && st.peek() == '[' && charArray[i] == ']')
                    st.pop();
                else if (!st.isEmpty() && st.peek() == '{' && charArray[i] == '}')
                    st.pop();
                else
                    return false;
            }
        }
        return st.isEmpty();
    }

*/