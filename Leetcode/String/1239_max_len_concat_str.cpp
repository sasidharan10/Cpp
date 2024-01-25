#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isUnique(string &s, string &t)
    {
        int n = s.length();
        int m = t.length();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (mp[idx] == 0)
                mp[idx]++;
            else
                return false;
        }
        for (int i = 0; i < m; i++)
        {
            int idx = t[i] - 'a';
            if (mp[idx] == 0)
                mp[idx]++;
            else
                return false;
        }
        return true;
    }
    // better
    int solve2(int ind, int n, string res, vector<string> &arr)
    {
        if (ind == n)
            return res.length();
        int notTake = INT_MIN, take = INT_MIN;
        if (!isUnique(res, arr[ind]))
        {
            notTake = solve2(ind + 1, n, res, arr);
        }
        else
        {
            notTake = solve2(ind + 1, n, res, arr);
            take = solve2(ind + 1, n, res + arr[ind], arr);
        }
        return max(take, notTake);
    }
    int maxLength2(vector<string> &arr)
    {
        int n = arr.size();
        return solve2(0, n, "", arr);
    }

    // optimal
    int solve(int ind, int val, int n, vector<int> &nums)
    {
        if (ind == n)
        {
            return __builtin_popcount(val);
        }
        int notTake = INT_MIN, take = INT_MIN;
        if ((val & nums[ind]) != 0)
        {
            notTake = solve(ind + 1, val, n, nums);
        }
        else
        {
            notTake = solve(ind + 1, val, n, nums);
            take = solve(ind + 1, val | nums[ind], n, nums);
        }
        return max(take, notTake);
    }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> st(arr[i].begin(), arr[i].end());
            if (st.size() != arr[i].size())
                continue;
            int val = 0;
            for (char ch : arr[i])
            {
                val = val | (1 << (ch - 'a'));
            }
            nums.push_back(val);
        }
        int m = nums.size();
        return solve(0, 0, m, nums);
    }
};
int main()
{
    Solution s;
    // vector<string> arr{"cha", "r", "act", "ers"};
    vector<string> arr{"cha", "r", "act", "ers"};
    cout << "Result: " << s.maxLength(arr) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

Youtube: https://www.youtube.com/watch?v=MqMvkrkerIY&lc=Ugzi4-kErtQCeL4WOzZ4AaABAg

algorithm:

- backtracking

- Finding all possible combinations of string concat, and check if its unique, if
  yes, we add to the "res" string.

*/

/*

1239. Maximum Length of a Concatenated String with Unique Characters

You are given an array of strings arr. A string s is formed by the
concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array
by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers"
("cha" + "ers") and "acters" ("act" + "ers").

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

*/