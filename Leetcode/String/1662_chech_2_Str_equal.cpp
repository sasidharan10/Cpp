#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    bool arrayStringsAreEqual2(vector<string> &word1, vector<string> &word2)
    {
        string temp1 = "", temp2 = "";
        int n1 = word1.size();
        int n2 = word2.size();
        for (int i = 0; i < n1; i++)
        {
            temp1 += word1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            temp2 += word2[i];
        }
        return temp1 == temp2;
    }
    // Better
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        // TC: O(3n)
        // SC: O(1)

        int n1 = word1.size();
        int n2 = word2.size();
        int len1 = 0, len2 = 0;
        for (int i = 0; i < n1; i++)
        {
            len1 += word1[i].size();
        }
        for (int i = 0; i < n2; i++)
        {
            len2 += word2[i].size();
        }
        if (len1 != len2)
            return false;
        int i = 0, j = 0, k1 = 0, k2 = 0, w1 = 0, w2 = 0;
        int m1 = word1[0].size();
        int m2 = word2[0].size();
        while ((w1 < len1) && (w2 < len2))
        {
            if (i >= m1)
            {
                m1 = word1[++k1].size();
                i = 0;
            }
            if (j >= m2)
            {
                m2 = word2[++k2].size();
                j = 0;
            }
            if (word1[k1][i] != word2[k2][j])
            {
                return false;
            }
            i++;
            j++;
            w1++;
            w2++;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<string> word1 = {"abc", "d", "defg"}, word2 = {"abcddefg"};
    cout << "Check If Two String Arrays are Equivalent: " << s.arrayStringsAreEqual(word1, word2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

Youtube:

algorithm:

*/

/*

1662. Check If Two String Arrays are Equivalent

Given two string arrays word1 and word2, return true if the two arrays represent
the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order
forms the string.


Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true

*/