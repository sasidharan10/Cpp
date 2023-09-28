#include <bits/stdc++.h>
using namespace std;
int lcsRecur(int ind1, int ind2, int count, string text1, string text2)
{

    if (ind1 == -1 || ind2 == -1)
        return count;
    if (text1[ind1] == text2[ind2])
    {
        count = lcsRecur(ind1 - 1, ind2 - 1, count + 1, text1, text2);
    }
    count = max({count, lcsRecur(ind1 - 1, ind2, 0, text1, text2), lcsRecur(ind1, ind2 - 1, 0, text1, text2)});
    return count;
}
int lcs(string &str1, string &str2)
{
    // TC: O(n*m)
    // SC: O(n*m)

    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
int main()
{
    string text1 = "wasdijkl", text2 = "wsdjkl";
    cout << "Longest Common Substring: " << lcs(text1, text2) << endl;
    int n = text1.size();
    int m = text2.size();
    int count = 0;
    cout << "Longest Common Substring: " << lcsRecur(n - 1, m - 1, count, text1, text2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

leetcode:

Youtube: https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28

algorithm:

*/