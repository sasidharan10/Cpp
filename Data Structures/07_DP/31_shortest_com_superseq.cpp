#include <bits/stdc++.h>
using namespace std;
string shortestSupersequence(string a, string b)
{
    // TC: O(n*m)
    // SC: O(n*m) + O(n+m - length(LCS))

    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += a[i - 1];
            i--;
        }
        else
        {
            ans += b[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += a[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += b[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s1 = "brute", s2 = "groot";
    cout << "Shortest common Supersequence: " << shortestSupersequence(s1, s2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493

leetcode:

Youtube: https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32&t=4s

algorithm:

*/