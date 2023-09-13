#include <bits/stdc++.h>
using namespace std;
// Recursion
int minimumPathSumRecur(int i, int j, vector<vector<int>> &triangle)
{
    if (i == triangle.size() - 1)
        return triangle[i][j];
    int down = triangle[i][j] + minimumPathSumRecur(i + 1, j, triangle);
    int diag = triangle[i][j] + minimumPathSumRecur(i + 1, j + 1, triangle);
    return min(down, diag);
}
// Memoization
int minimumPathSumMem(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
        return triangle[i][j];
    if (dp[i][j] != 1e9)
        return dp[i][j];
    int down = triangle[i][j] + minimumPathSumRecur(i + 1, j, triangle);
    int diag = triangle[i][j] + minimumPathSumRecur(i + 1, j + 1, triangle);
    return dp[i][j] = min(down, diag);
}
// Tabulation
int minimumPathSumTab(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}
// Space Optimization
int minimumPathSumSpc(vector<vector<int>> &triangle, int n)
{
    vector<int> prev(n, 0);
    for (int j = 0; j < n; j++)
    {
        prev[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> cur(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int diag = triangle[i][j] + prev[j + 1];
            cur[j] = min(down, diag);
        }
        prev = cur;
    }
    return prev[0];
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    int i = 0;
    int j = 0;
    // return minimumPathSumRecur(i, j, triangle);
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    // return minimumPathSumMem(i, j, triangle, dp);
    // return minimumPathSumTab(triangle, n);
    return minimumPathSumSpc(triangle, n);
}
int main()
{
    int n = 4;
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9, 10}};
    cout << "Minimum path sum: " << minimumPathSum(triangle, n);
    return 0;
}