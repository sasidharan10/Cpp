#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Using stack
    int minimumDeletions(string s)
    {
        // TC: O(n)
        // SC: O(n)

        int n = s.length();
        int cnt = 0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b')
            {
                st.pop();
                cnt++;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    string str = "aababbab";
    cout << "Result: " << s.minimumDeletions(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1653. Minimum Deletions to Make String Balanced

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no
pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.

Constraints:

1 <= s.length <= 10^5
s[i] is 'a' or 'b'​​.

*/

/*
************* Java Code **************



*/