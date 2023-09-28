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
int canYouMake(string &s1, string &s2)
{
    int commonLength = longestCommonSubsequenceSpc(s1, s2);
    int res = s1.size() + s2.size() - 2 * commonLength;
    return res;
}
int main()
{
    string str1 = "abcd", str2 = "anc";
    cout << "Longest Common Subsequence: " << canYouMake(str1, str2);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/can-you-make_4244510

leetcode:

Youtube: https://www.youtube.com/watch?v=yMnH0jrir0Q&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=31

algorithm:

*/