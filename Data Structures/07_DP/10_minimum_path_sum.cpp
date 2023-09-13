#include <bits/stdc++.h>
using namespace std;
// Recursion
int minSumPathRecur(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    int up = grid[i][j] + minSumPathRecur(i - 1, j, grid);
    int left = grid[i][j] + minSumPathRecur(i, j - 1, grid);
    return min(up, left);
}
// Memoization
int minSumPathMem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + minSumPathMem(i - 1, j, grid, dp);
    int left = grid[i][j] + minSumPathMem(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
// Tabulation
int minSumPathTab(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = grid[i][j];
            int left = grid[i][j];
            if (i > 0)
                up += dp[i - 1][j];
            else
                up += 1e9;
            if (j > 0)
                left += dp[i][j - 1];
            else
                up += 1e9;
            dp[i][j] = min(left, up);
        }
    }
    return dp[n - 1][m - 1];
}
// Space Optimization
int minSumPathSpc(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
                continue;
            }
            int up = grid[i][j];
            int left = grid[i][j];
            if (i > 0)
                up += prev[j];
            else
                up += 1e9;
            if (j > 0)
                left += temp[j - 1];
            else
                left += 1e9;
            temp[j] = min(left, up);
        }
        prev = temp;
    }
    return prev[m - 1];
}
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // return minSumPathRecur(n - 1, m - 1, grid);
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return minSumPathMem(n - 1, m - 1, grid, dp);
    // return minSumPathTab(grid);
    return minSumPathSpc(grid);
}
int main()
{
    vector<vector<int>> grid{{1, 2, 3},
                             {4, 5, 4},
                             {7, 5, 9}};
    cout << "Minimum path sum: " << minSumPath(grid);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349

leetcode:

Youtube: https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

algorithm:

*/