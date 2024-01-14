#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // TC: O(n * MlogM) where M = count of chars
        // SC: O(26) + O(M)

        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 != n2)
            return false;
        vector<int> mp1(26, 0), mp2(26, 0);
        for (int i = 0; i < n1; i++)
        {
            mp1[word1[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            int ch = word2[i] - 'a';
            if (!mp1[ch])
                return false;
            mp2[ch]++;
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1 == mp2;
    }
};
int main()
{
    Solution s;
    string word1 = "cabbba", word2 = "abbccc";
    cout << "Determine if Two Strings Are Close: " << s.closeStrings(word1, word2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/determine-if-two-strings-are-close

Youtube:

algorithm:

- As per the given condition, if the 2 strings have different length,
  then we can return false.
- The characters in both strings should be same, as we can only swap the characters or
  change their occurence count, so if any characters are different in both,
  we can return false.
- we get the character counts from both strings, and check if the counts are
  are, since if counts are different, then we cannot transform into same strings
  Ex: str1 = "abbbbb" str2 = "aaabbb", str2 can be changed to "bbbaaa" only.
- here as per the given condition, we can only interchange the character count,
  but cannot change the counts.
- Hence we sort the counts, and check if its equal.

*/

/*

1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character
into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"

*/