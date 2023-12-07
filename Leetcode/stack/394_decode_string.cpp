#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        string ans = "";
        stack<string> ch;
        stack<int> num;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                // if the number contains multiple digit
                int j = i;
                string tp = "";
                while (s[j] >= '0' && s[j] <= '9')
                {
                    tp += s[j];
                    j++;
                }
                int t = stoi(tp);
                num.push(t);
                i = j - 1;
            }
            else if (s[i] != ']')
            {
                string str = "";
                str += s[i];
                ch.push(str);
            }
            else
            {
                string temp1 = "", temp2 = "";
                while (!ch.empty() && ch.top() != "[")
                {
                    temp1 += ch.top();
                    ch.pop();
                }
                ch.pop();
                int cnt = num.top();
                num.pop();
                for (int i = 0; i < cnt; i++)
                {
                    temp2 += temp1;
                }
                ch.push(temp2);
            }
        }
        while (!ch.empty())
        {
            ans += ch.top();
            ch.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "3[a2[c]]";
    cout << "Decoded String: " << s.decodeString(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/decode-string/

Youtube: https://www.youtube.com/watch?v=E9qHRcQXmDk&t=601s

algorithm:


- 3[a2[c]]
- 3[acc]
- accaccacc

- We store the numbers and and characters in 2 stacks. when we encounter ']' tag
  it means, we stored the string i the stack, aand we need to decode it.
- We pop from the "ch" stack, until we find '[', which means that section is empty.
- Then we pop 1 number from "num" stack, which keeps the count of that string.
- we multiply that string by that count, and again push in into the "ch" stack
- We do this until, we push all characters in stack.
- The resultant string can be formed, by popping the remaning characters
  from the "ch" stack, and concat it. It should be reversed also, since we are fetching it 
  from the stack.

*/

/*

394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the
square brackets is being repeated exactly k times. Note that k is guaranteed
to be a positive integer.

You may assume that the input string is always valid; there are no extra white
spaces, square brackets are well-formed, etc. Furthermore, you may assume
that the original data does not contain any digits and that digits are
only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/