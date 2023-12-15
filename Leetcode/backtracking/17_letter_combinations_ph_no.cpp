#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<string> ans;

public:
    void solve(int idx, string digits, string temp, unordered_map<char, string> &mp)
    {
        if (idx == digits.length())
        {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string letters = mp[ch];
        int m = letters.length();
        for (int i = 0; i < m; i++)
        {
            temp.push_back(letters[i]);
            solve(idx + 1, digits, temp, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        // TC: O(4^n * n)
        // SC: O(n)
        
        if (digits.length() == 0)
            return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp, mp);
        return ans;
    }
};
int main()
{
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/letter-combinations-of-a-phone-number

Youtube:

algorithm:

*/

/*

17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is
given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/