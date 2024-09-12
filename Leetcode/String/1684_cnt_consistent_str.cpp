#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better = using map
    int countConsistentStrings2(string allowed, vector<string> &words)
    {
        // TC: O(n*m)
        // SC: O(26)

        int n = words.size();
        int mp[26] = {0};
        for (int i = 0; i < allowed.size(); i++)
        {
            mp[allowed[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int len = 0;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (mp[words[i][j] - 'a'] > 0)
                    len++;
                else
                    break;
            }
            if (words[i].length() == len)
                res++;
        }
        return res;
    }

    // Optimal - using bitmask
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        // TC: O(n*m)
        // SC: O(1)
        
        int n = words.size();
        int mask = 0;
        for (int i = 0; i < allowed.size(); i++)
        {
            int temp = allowed[i] - 'a';
            mask |= (1 << temp);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            bool isConsistent = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                int temp = words[i][j] - 'a';
                if ((mask & (1 << temp)) == 0)
                {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent)
                res++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> words{"ad", "bd", "aaab", "baa", "badab"};
    string allowed = "ab";
    cout << "Result: " << s.countConsistentStrings(allowed, words) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-the-number-of-consistent-strings

Youtube: https://www.youtube.com/watch?v=QEIKg95HKzg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashSet/Count%20the%20Number%20of%20Consistent%20Strings.cpp

algorithm:

- Optimal Approach:

- Same method, but instead of using map, we use bitmask to check if the current character
  is present in the allowed word.

*/

/*

1684. Count the Number of Consistent Strings

You are given a string allowed consisting of distinct characters and an array of strings words.
A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

Constraints:

1 <= words.length <= 10^4
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

*/

/*
************* Java Code **************

    public static int countConsistentStrings(String allowed, String[] words) {
        int n = words.length;
        int[] mp = new int[26];
        for (int i = 0; i < allowed.length(); i++) {
            mp[allowed.charAt(i) - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = 0; j < words[i].length(); j++) {
                if (mp[words[i].charAt(j) - 'a'] > 0)
                    len++;
                else
                    break;
            }
            if (words[i].length() == len)
                res++;
        }
        return res;
    }

    // Optimal

    public static int countConsistentStrings(String allowed, String[] words) {
        int n = words.length;
        int mask = 0;
        for (int i = 0; i < allowed.length(); i++) {
            int temp = allowed.charAt(i) - 'a';
            mask |= (1 << temp);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            boolean isConsistent = true;
            for (int j = 0; j < words[i].length(); j++) {
                int temp = words[i].charAt(j) - 'a';
                if ((mask & (1 << temp)) == 0) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent)
                res++;
        }
        return res;
    }

*/