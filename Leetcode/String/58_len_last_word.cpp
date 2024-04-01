#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord2(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        bool flag = false;
        int len = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ' && !flag)
            {
                flag = true;
                len++;
            }
            else if (s[i] != ' ')
                len++;
            else if (s[i] == ' ' && flag)
                return len;
            else if (s[i] == ' ')
                continue;
        }
        return len;
    }

    // Simple Version
    int lengthOfLastWord(string s)
    {
        // TC: O(n)
        // SC: O(1)

        int n = s.length();
        int i = n - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        int len = 0;
        while (i >= 0 && s[i] != ' ')
        {
            i--;
            len++;
        }
        return len;
    }
};
int main()
{
    Solution s;
    string str = "   fly me   to   the moon  ";
    cout << "Length of Last Word: " << s.lengthOfLastWord(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/length-of-last-word/

Youtube: https://www.youtube.com/watch?v=hi0I4UiPu-M

Code Link:

*/

/*

58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

*/

/*
************* Java Code **************

public static int lengthOfLastWord(String s) {
        int n = s.length();
        boolean flag = false;
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ' && !flag) {
                flag = true;
                len++;
            } else if (s.charAt(i) != ' ')
                len++;
            else if (s.charAt(i) == ' ' && flag)
                return len;
            else if (s.charAt(i) == ' ')
                continue;
        }
        return len;
    }

*/