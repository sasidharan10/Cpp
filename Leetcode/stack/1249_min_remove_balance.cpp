#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - storing culprit index using set
    string minRemoveToMakeValid3(string s)
    {
        // TC: O(n) + O(n) for storing and searching the culprit index
        // SC: O(2n)

        int n = s.length();
        stack<int> st;
        unordered_set<int> removeIndex;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                    st.pop();
                else
                    removeIndex.insert(i);
            }
        }

        // suppose the input is  "(("
        // Then, we need to remove those also

        while (!st.empty())
        {
            removeIndex.insert(st.top());
            st.pop();
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (removeIndex.find(i) != removeIndex.end())
                continue;
            else
                res.push_back(s[i]);
        }
        return res;
    }

    string minRemoveToMakeValid2(string s)
    {
        // TC: O(3n) - 2 traversal, reversing
        // SC: O(2n) - using 2 strings

        int n = s.length();
        string temp = "";
        int open = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
                temp.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (open > 0)
                {
                    open--;
                    temp.push_back(s[i]);
                }
            }
            else
                temp.push_back(s[i]);
        }
        n = temp.length();
        string res = "";
        int close = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp[i] == ')')
            {
                close++;
                res.push_back(temp[i]);
            }
            else if (temp[i] == '(')
            {
                if (close > 0)
                {
                    close--;
                    res.push_back(temp[i]);
                }
            }
            else
                res.push_back(temp[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        string temp = "";
        int open = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
                temp.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (open > 0)
                {
                    open--;
                    temp.push_back(s[i]);
                }
            }
            else
                temp.push_back(s[i]);
        }

        n = temp.length();
        string res = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp[i] == '(' && open > 0)
                open--;
            else
                res.push_back(temp[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution s;
    string str = "lee(t(c)o)de)";
    cout << "String after Balancing Parenthesis: " << s.minRemoveToMakeValid(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Youtube: https://www.youtube.com/watch?v=NNxaYz0nrk0

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in
any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

*/

/*
************* Java Code **************

// Using stack

public static String minRemoveToMakeValid(String s) {
        int n = s.length();
        Stack<Integer> st = new Stack<>();
        HashSet<Integer> removeIndex = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                st.push(i);
            } else if (s.charAt(i) == ')') {
                if (!st.isEmpty())
                    st.pop();
                else
                    removeIndex.add(i);
            }
        }
        while (!st.isEmpty()) {
            removeIndex.add(st.pop());
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (removeIndex.contains(i))
                continue;
            else
                res.append(s.charAt(i));
        }
        return res.toString();
    }

// Optimal 

public static String minRemoveToMakeValid(String s) {
        int n = s.length();
        StringBuilder temp = new StringBuilder();
        int open = 0;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                open++;
                temp.append(ch);
            } else if (ch == ')') {
                if (open > 0) {
                    open--;
                    temp.append(ch);
                }
            } else
                temp.append(ch);
        }
        n = temp.length();
        StringBuilder res = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            char ch = temp.charAt(i);
            if (ch == '(' && open > 0)
                open--;
            else
                res.append(ch);
        }
        res.reverse();
        return res.toString();
    }

*/