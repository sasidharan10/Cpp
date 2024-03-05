#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumLength(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j && s[i] == s[j])
        {
            char ch = s[i];
            while (i < j && ch == s[i])
            {
                i++;
            }
            while (i <= j && ch == s[j])
            {
                j--;
            }
        }
        return (j - i + 1);
    }
};
int main()
{
    Solution s;
    // string str = "cabaabac";
    string str = "ca";
    // string str = "aabccabba";
    // string str = "bcbcb";
    cout << "Result: " << s.minimumLength(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

Youtube: https://www.youtube.com/watch?v=skEofEGj46Y

algorithm:

- Optimal Approach:

- Use 2 pointer, can eliminate same chars from both ends until condition becomes
  false.
- take care of edge cases like "aa" and "bcbcb".

*/

/*

1750. Minimum Length of String After Deleting Similar Ends

Given a string s consisting only of characters 'a', 'b', and 'c'. You are
asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number
of times (possibly zero times).

Example 1:

Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.

Example 2:

Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".

Example 3:

Input: s = "aabccabba"
Output: 3
Explanation: An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".

*/

/*

public static int minimumLength(String s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j && s.charAt(i) == s.charAt(j)) {
            char ch = s.charAt(i);
            while (i < j && ch == s.charAt(i)) {
                i++;
            }
            while (i <= j && ch == s.charAt(j)) {
                j--;
            }
        }
        return (j - i + 1);
    }

*/