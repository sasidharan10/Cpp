#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        // TC: O(n)
        // SC: O(n)

        string res = "";
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            res += word1[i++];
            res += word2[j++];
        }
        while (i < n1)
            res += word1[i++];
        while (j < n2)
            res += word2[j++];
        return res;
    }
};
int main()
{
    Solution s;
    string word1 = "abcd", word2 = "pq";
    cout << "Merge Strings Alternately: " << s.mergeAlternately(word1, word2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-strings-alternately

Youtube:

algorithm:

*/

/*

1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters
in alternating order, starting with word1. If a string is longer than the other,
append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d

*/

/*   
************* Java Code **************

    public static String mergeAlternately(String word1, String word2) {
        StringBuilder res = new StringBuilder();
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            res.append(word1.charAt(i++));
            res.append(word2.charAt(j++));
        }
        while (i < n1)
            res.append(word1.charAt(i++));
        while (j < n2)
            res.append(word2.charAt(j++));
        return res.toString();
    }

*/