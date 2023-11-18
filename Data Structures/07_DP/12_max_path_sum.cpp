#include <bits/stdc++.h>
using namespace std;
// Recursion
int getMaxPathSumRecur(int i, int j, vector<vector<int>> &matrix)
{
    // TC: O(3^n)
    // SC: O(n)

    int m = matrix[0].size();
    if (j < 0 || j >= m)
        return -1e8;
    if (i == 0)
        return matrix[i][j];
    int up = matrix[i][j] + getMaxPathSumRecur(i - 1, j, matrix);
    int ld = matrix[i][j] + getMaxPathSumRecur(i - 1, j - 1, matrix);
    int rd = matrix[i][j] + getMaxPathSumRecur(i - 1, j + 1, matrix);
    return max({up, ld, rd});
}
// Memoization
int getMaxPathSumMem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // TC: O(n*m)
    // SC: O(n) + O(n*m)

    int m = matrix[0].size();
    if (j < 0 || j >= m)
        return -1e8;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1e8)
        return dp[i][j];
    int up = matrix[i][j] + getMaxPathSumMem(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + getMaxPathSumMem(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + getMaxPathSumMem(i - 1, j + 1, matrix, dp);
    return dp[i][j] = max({up, ld, rd});
}
// Tabulation
int getMaxPathSumTab(vector<vector<int>> &matrix)
{
    // TC: O(n*m)
    // SC: O(n*m)

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int ld = matrix[i][j];
            int rd = matrix[i][j];
            if (j > 0)
                ld += dp[i - 1][j - 1];
            else
                ld += -1e8;
            if (j < m - 1)
                rd += dp[i - 1][j + 1];
            else
                rd += -1e8;
            dp[i][j] = max({up, ld, rd});
        }
    }
    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}
// Space Optimization
int getMaxPathSumSpc(vector<vector<int>> &matrix)
{
    // TC: O(n*m)
    // SC: O(m)

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> cur(m, 0);
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            int ld = matrix[i][j];
            int rd = matrix[i][j];
            if (j > 0)
                ld += prev[j - 1];
            else
                ld += -1e8;
            if (j < m - 1)
                rd += prev[j + 1];
            else
                rd += -1e8;
            cur[j] = max({up, ld, rd});
        }
        prev = cur;
    }
    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    // return getMaxPathSumTab(matrix);
    return getMaxPathSumSpc(matrix);
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>> dp(m, vector<int>(n, -1e8));
    for (int j = 0; j < m; j++)
    {
        // int temp = getMaxPathSumRecur(n - 1, j, matrix);
        int temp = getMaxPathSumMem(n - 1, j, matrix, dp);
        maxi = max(maxi, temp);
    }
    return maxi;
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};
    cout << "Max path sum: " << getMaxPathSum(matrix);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998

leetcode: 

Youtube: https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13

algorithm: 

*/