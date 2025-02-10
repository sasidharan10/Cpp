#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string clearDigits(string s)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            int ch = s[i] - '0';
            if (ch >= 0 && ch <= 9)
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution s;
    string str = "abc";
    // string str = "cb34";
    cout << "Result: " << s.clearDigits(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/clear-digits/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- use stack.

*/

/*

3174. Clear Digits

You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Example 1:

Input: s = "abc"
Output: "abc"
Explanation:
There is no digit in the string.

Example 2:

Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes "".

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.

*/

/*
************* Java Code **************

    public String clearDigits(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i) - '0';
            if (ch >= 0 && ch <= 9) {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }
        StringBuilder res = new StringBuilder();
        while (!st.empty()) {
            res.append(st.peek());
            st.pop();
        }
        res.reverse();
        return res.toString();
    }

*/