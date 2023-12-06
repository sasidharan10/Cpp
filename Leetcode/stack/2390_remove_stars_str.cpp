#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute (using stack)
    string removeStars2(string s)
    {
        string ans = "";
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
                st.push(s[i]);
            else
            {
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    // Optimal
    string removeStars(string s)
    {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
                ans.push_back(s[i]);
            else
                ans.pop_back();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "leet**cod*e";
    cout << "Result: " << s.removeStars(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/removing-stars-from-a-string

Youtube:

algorithm:

//Optimal
- Push all character in the string, pop it if we encounter a '*'

// Brute
- Store chars in stack, pop it if we encounter a '*'.
- Return the remaning string in stack.

*/


/*

2390. Removing Stars From a String

You are given a string s, which contains stars *.
In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 
Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

*/
