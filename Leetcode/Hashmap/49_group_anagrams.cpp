#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto &&it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(nums);
    cout << "Anagrams Grouped: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/group-anagrams/

Youtube:

algorithm:

*/

/*

49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can
return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/