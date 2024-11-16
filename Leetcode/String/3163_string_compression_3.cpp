#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string compressedString(string word)
    {
        string comp = "";
        int n = word.length();
        int i = 0;
        while (i < n)
        {
            int count = 0;
            char ch = word[i];
            while (i < n && count < 9 && word[i] == ch)
            {
                count++;
                i++;
            }
            comp += to_string(count) + ch;
        }
        return comp;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/string-compression-iii

Youtube: https://www.youtube.com/watch?v=cbo80sOKci4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/String%20Compression%20III.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

3163. String Compression III

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

Example 1:
Input: word = "abcde"
Output: "1a1b1c1d1e"

Explanation:
Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the
prefix in each operation.
For each prefix, append "1" followed by the character to comp.

Example 2:
Input: word = "aaaaaaaaaaaaaabb"
Output: "9a5a2b"

Explanation:
Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as
the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.

Constraints:

1 <= word.length <= 2 * 10^5
word consists only of lowercase English letters.

*/

/*
************* Java Code **************

    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int n = word.length();
        int i = 0;

        while (i < n) {
            int count = 0;
            char ch = word.charAt(i);

            while (i < n && count < 9 && word.charAt(i) == ch) {
                count++;
                i++;
            }

            comp.append(count).append(ch);
        }

        return comp.toString();
    }

*/