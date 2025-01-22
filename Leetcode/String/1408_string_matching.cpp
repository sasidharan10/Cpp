#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - creating new substring and then matching with the target.
    vector<string> stringMatching2(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> res;
        for (int i = 0; i < n; i++)
        {
            int curLen = words[i].length();
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int len = words[j].length();
                if (curLen > len)
                    continue;
                for (int k = 0; k < len; k++)
                {
                    string temp = words[j].substr(k, curLen);
                    if (words[i] == temp)
                        res.insert(words[i]);
                }
            }
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }

    // Brute force
    vector<string> stringMatching(vector<string> &words)
    {
        // TC: O(n^2 * m), where m = avg length of words[].
        // SC: O(1)
        
        int n = words.size();
        unordered_set<string> res;
        for (int i = 0; i < n; i++)
        {
            int curLen = words[i].length();
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int len = words[j].length();
                if (curLen > len)
                    continue;
                for (int k = 0; k <= len - curLen; k++)
                {
                    int start = k, end = k + curLen;
                    while (start < end)
                    {
                        if (words[i][start - k] != words[j][start])
                            break;
                        start++;
                    }
                    if (start == end)
                        res.insert(words[i]);
                }
            }
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words{"mass", "as", "hero", "superhero"};
    vector<string> ans = s.stringMatching(words);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/string-matching-in-an-array

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- KMP algo, incomplete

*/

/*

1408. String Matching in an Array

Given an array of string words, return all strings in words that is a substring of another word. You can
return the answer in any order.

A substring is a contiguous sequence of characters within a string

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.

*/

/*
************* Java Code **************



*/