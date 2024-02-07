#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool static comp(pair<int, char> &p1, pair<int, char> &p2)
    {
        return p1.first > p2.first;
    }
    // better
    string frequencySort2(string s)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int, char>> newMp;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            newMp.push_back({it->second, it->first});
        }
        sort(newMp.begin(), newMp.end(), comp);
        string ans = "";
        for (auto &&it : newMp)
        {
            int freq = it.first;
            char ch = it.second;
            for (int i = 0; i < freq; i++)
            {
                ans += ch;
            }
        }
        return ans;
    }
    // optimal
    string frequencySort(string s)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = s.length();
        vector<pair<char, int>> mp(123);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int freq = mp[ch].second;
            mp[ch] = {ch, freq + 1};
        }
        auto lambda = [](pair<char, int> &p1, pair<char, int> &p2)
        {
            return p1.second > p2.second;
        };

        sort(mp.begin(), mp.end(), lambda);
        string ans = "";
        for (auto &&it : mp)
        {
            char ch = it.first;
            int freq = it.second;
            if (freq > 0)
            {
                string temp = string(freq, ch);
                ans += temp;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "Aabb";
    cout << "Result: " << s.frequencySort(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-characters-by-frequency/

Youtube: https://www.youtube.com/watch?v=pnxShVARLLw

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency
of the characters. The frequency of a character is the number of
times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so
both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/