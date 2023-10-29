#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(int i, int j, string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        if (i >= j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s);
        return 0;
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxlen = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (solve(i, j, s) && j - i + 1 > maxlen)
                {
                    start = i;
                    maxlen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
int main()
{
    Solution s;
    string str = "babad";
    cout << "Longest Palindromic Substring: " << s.longestPalindrome(str) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/