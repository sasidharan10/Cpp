#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findScore2(string &s, string t, int points, int &score)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[1] && !st.empty() && st.top() == t[0])
            {
                st.pop();
                score += points;
            }
            else
                st.push(s[i]);
        }
        string temp = "";
        while (!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    // Better - using stack.
    int maximumGain2(string s, int x, int y)
    {
        // TC: O(n) + O(n)
        // SC: O(n)

        int n = s.length();
        int score = 0;
        string temp = "";
        if (x > y)
        {
            temp = findScore2(s, "ab", x, score);    // temp is the remaining str after removing all "ab"'s
            temp = findScore2(temp, "ba", y, score); // now we send temp, to find if any "ba" exists.
        }
        else
        {
            temp = findScore2(s, "ba", y, score);
            temp = findScore2(temp, "ab", x, score);
        }
        return score;
    }

    string findScore(string &s, string t, int points, int &score)
    {
        int n = s.length();
        int i = 0; // used as writer
        int j = 0; // used as reader
        while (j < n)
        {
            s[i] = s[j];
            i++;

            if (i >= 2 && s[i - 2] == t[0] && s[i - 1] == t[1])
            {
                i -= 2;
                score += points;
            }
            j++;
        }
        s.erase(s.begin() + i, s.end());
        return s;
    }

    // Optimal - using 2 pointer.
    int maximumGain(string s, int x, int y)
    {
        // TC: O(n) + O(n)
        // SC: O(n)

        int n = s.length();
        int score = 0;
        string temp = "";
        if (x > y)
        {
            temp = findScore(s, "ab", x, score);    // temp is the remaining str after removing all "ab",
            temp = findScore(temp, "ba", y, score); // now we send temp, to remove all "ba".
        }
        else
        {
            temp = findScore(s, "ba", y, score);
            temp = findScore(temp, "ab", x, score);
        }
        return score;
    }
};
int main()
{
    Solution s;
    string str = "cdbcbbaaabab";
    int x = 4, y = 5;
    cout << "Result: " << s.maximumGain(str, x, y) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-score-from-removing-substrings

Youtube: https://www.youtube.com/watch?v=WTAjAcjSTqM

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Maximum%20Score%20From%20Removing%20Substrings.cpp

algorithm:

- Brute Force Approach:

- The approach is to find whether "ab" or "ba" has more value.
- Lets say "ab" has  max points. Then we try to find "ab" in the given string.
- Its evident that once all "ab" are removed, it cannot appear again.
- Now remove all possible "ba" from the string and finally add the scores and return it.
- We use stack to efficiently find and delete the substrings.

- Optimal Approach:

- refer video
- We use 2 pointer approach, where "i" will be the writer and "j" will be the reader.
- Whatever "j" reads that is assigned to "i".
- Then we move the "i" pointer.
- Everytime, the "i" pointer also checks if its previous 2 characters matches the target?
  if yes, then we move i-=2 backwards.
- At last, the "i" pointer will point the end of the new string.
- We delete all chars after "i" and return the new string after removing all the possible
  "ab" or "ba".

*/

/*

1717. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations
any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

Constraints:

1 <= s.length <= 10^5
1 <= x, y <= 10^4
s consists of lowercase English letters.

*/

/*
************* Java Code **************

    public static String findScore(String s, String t) {
        int n = s.length();
        int i = 0; // used as writer
        int j = 0; // used as reader
        StringBuilder sb = new StringBuilder();
        while (j < n) {
            sb.append(s.charAt(j));
            i++;

            if (i >= 2 && sb.charAt(i - 2) == t.charAt(0) && sb.charAt(i - 1) == t.charAt(1)) {
                sb.delete(i - 2, i);
                i -= 2;
            }
            j++;
        }
        return sb.toString();
    }

    public static int maximumGain(String s, int x, int y) {
        int n = s.length();
        String maxStr = (x > y) ? "ab" : "ba";
        String minStr = (x < y) ? "ab" : "ba";

        int score = 0;
        String tempFirst = findScore(s, maxStr);
        int len1 = tempFirst.length();
        int removedCount = (n - len1) / 2;
        score += removedCount * Math.max(x, y);

        String tempSecond = findScore(tempFirst, minStr);
        int len2 = tempSecond.length();
        removedCount = (len1 - len2) / 2;
        score += removedCount * Math.min(x, y);

        return score;
    }

*/