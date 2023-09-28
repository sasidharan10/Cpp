#include <bits/stdc++.h>
using namespace std;
// Space Optimization
int longestCommonSubsequenceSpc(string text1, string text2)
{
    // TC: O(n*m)
    // SC: O(m)

    int n = text1.length();
    int m = text2.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 0; j <= m; j++)
    {
        prev[j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    // return longestCommonSubsequenceTab(s, t);
    return longestCommonSubsequenceSpc(s, t);
}
int minimumInsertions(string &str)
{
    return str.size() - longestPalindromeSubsequence(str);
}
int main()
{
    string str = "bbabcbcab";
    cout << "Longest Common Subsequence: " << longestPalindromeSubsequence(str);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-palindrome_985293

leetcode:

Youtube: https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30

algorithm:

*/