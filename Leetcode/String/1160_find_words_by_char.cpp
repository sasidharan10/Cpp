#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        // TC: O(n)
        // SC: O(2*26)
        
        int ans = 0;
        int n = words.size();
        int len = chars.length();
        vector<int> mp(26, 0), temp(26, 0);
        for (int i = 0; i < len; i++)
        {
            mp[chars[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(26, 0);
            bool isPossible = true;
            int m = words[i].length();
            for (int j = 0; j < m; j++)
            {
                char ch = words[i][j];
                temp[ch - 'a']++;
            }
            for (int j = 0; j < 26; j++)
            {
                if (temp[j] > mp[j])
                {
                    isPossible = false;
                }
            }
            if (isPossible)
                ans += m;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"hello", "world", "leetcode"};
    string chars = "welldonehoneyr";
    cout << "The Sum of lengths of all good strings: " << s.countCharacters(words, chars) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

Youtube: https://www.youtube.com/watch?v=0RpZxrkLCyg

algorithm:

*/

/*

1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


*/