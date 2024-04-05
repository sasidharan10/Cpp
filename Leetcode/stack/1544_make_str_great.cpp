#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - Using stack
    string makeGood2(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if ((st.size() > 0) && (st.top() - 32 == ch || st.top() + 32 == ch))
                st.pop();
            else
                st.push(ch);
        }
        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }

    // Optimal 
    string makeGood(string s)
    {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if ((res.size() > 0) && (res.back() - 32 == ch || res.back() + 32 == ch))
                res.pop_back();
            else
                res.push_back(ch);
        }
        return res;
    }
};
int main()
{
    Solution s;
    // string str = "abBAcC";
    string str = "leEeetcode";
    cout << "Result: " << s.makeGood(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/make-the-string-great/

Youtube: https://www.youtube.com/watch?v=J43ZIltH3AY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Make%20The%20String%20Great.cpp

algorithm:

-

*/

/*

1544. Make The String Great

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string
bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be
unique under the given constraints.

Notice that an empty string is also good.

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result
"leEeetcode" to be reduced to "leetcode".

Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:

Input: s = "s"
Output: "s"

*/

/*
************* Java Code **************

public static String makeGood(String s) {
        int n = s.length();
        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if ((temp.length() > 0)
                    && (temp.charAt(temp.length() - 1) - 32 == ch || temp.charAt(temp.length() - 1) + 32 == ch))
                temp.deleteCharAt(temp.length() - 1);
            else
                temp.append(ch);
        }
        return temp.toString();
    }

// using stack:

public static String makeGood(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if ((st.size() > 0) && (st.peek() - 32 == ch || st.peek() + 32 == ch))
                st.pop();
            else
                st.push(ch);
        }
        String res = "";
        while (!st.empty()) {
            res = st.pop() + res;
        }
        return res;
    }
*/
