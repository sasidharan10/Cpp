#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    int countPalindromicSubsequence2(string s)
    {
        // TC: O(26*n) ~ O(n)
        // SC: O(26)

        unordered_set<char> letters;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            letters.insert(s[i]);
        }
        int result = 0;
        for (auto letter : letters)
        {
            int left_idx = -1;
            int right_idx = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == letter)
                {
                    if (left_idx == -1)
                    {
                        left_idx = i;
                    }
                    right_idx = i;
                }
            }
            unordered_set<char> st;
            for (int middle = left_idx + 1; middle < right_idx; middle++)
            {
                st.insert(s[middle]);
            }
            result += st.size();
        }
        return result;
    }
    
    // Optimal
    int countPalindromicSubsequence(string s)
    {
        // TC: O(26*n) ~ O(n)
        // SC: O(26)
        
        vector<pair<int, int>> v(26, {-1, -1});
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int idx = s[i]-'a';
            if (v[idx].first == -1)
                v[idx].first = i;
            v[idx].second = i;
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            int left_idx = v[i].first;
            int right_idx = v[i].second;
            if (left_idx == -1)
                continue;
            unordered_set<char> st;
            for (int middle = left_idx + 1; middle < right_idx; middle++)
            {
                st.insert(s[middle]);
            }
            result += st.size();
        }
        return result;
    }
};
int main()
{
    Solution s;
    string str = "bbcbaba";
    cout << "Unique Length-3 Palindromic Subsequences: " << s.countPalindromicSubsequence(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/unique-length-3-palindromic-subsequences

Youtube: https://www.youtube.com/watch?v=EdEvy2_o5OE

algorithm:

- Since we need to find palindromes of size 3, we know that the first and last
  character of the palindrome should be same.
- Using this trick, we can first and last index of a character, and then find all
  the unique characters between them as they all are palindromes.

*/