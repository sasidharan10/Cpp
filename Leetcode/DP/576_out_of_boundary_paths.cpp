#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int M;
    int N;
    int mod = 1e9 + 7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Recursion
    int solve(int i, int j, int m, int n, int maxMove)
    {
        // TC: O(4 ^ maxMove)
        // SC: O(maxMove)

        if (maxMove < 0)
            return 0;
        if ((i == -1 || i == m || j == -1 || j == n) && maxMove >= 0)
            return 1;
        int left = (solve(i, j - 1, m, n, maxMove - 1) % mod);
        int right = (solve(i, j + 1, m, n, maxMove - 1) % mod);
        int up = (solve(i - 1, j, m, n, maxMove - 1) % mod);
        int down = (solve(i + 1, j, m, n, maxMove - 1) % mod);
        return ((left + right) % mod + (up + down) % mod) % mod;
    }
    // Memoization
    int solveMem(int i, int j, int m, int n, int maxMove, vector<vector<vector<int>>> &dp)
    {
        // TC: O(m * n * maxMove) + O(maxMove)
        // SC: O(m * n * maxMove)

        if (maxMove < 0)
            return 0;
        if ((i < 0 || i >= m || j < 0 || j >= n) && maxMove >= 0)
            return 1;
        if (dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        int left = (solveMem(i, j - 1, m, n, maxMove - 1, dp) % mod);
        int right = (solveMem(i, j + 1, m, n, maxMove - 1, dp) % mod);
        int up = (solveMem(i - 1, j, m, n, maxMove - 1, dp) % mod);
        int down = (solveMem(i + 1, j, m, n, maxMove - 1, dp) % mod);
        return dp[i][j][maxMove] = ((left + right) % mod + (up + down) % mod) % mod;
    }
    // Tabulation
    int solveTab(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 2, vector<int>(maxMove + 2, 0)));
        for (int k = 0; k <= maxMove; k++)
        {
            for (int i = 0; i <= m + 1; i++)
            {
                for (int j = 0; j <= n + 1; j++)
                {
                    dp[0][j][k] = dp[i][0][k] = dp[m][j][k] = dp[i][n][k] = 1;
                }
            }
        }
        // for (auto &&it1 : dp)
        // {
        //     for (auto &&it2 : it1)
        //     {
        //         for (auto &&it3 : it2)
        //         {
        //             cout << it3 << ", ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        //     cout << endl;
        // }
        for (int k = 1; k <= maxMove; k++)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    int left = (dp[i][j - 1][maxMove - 1] % mod);
                    int right = (dp[i][j + 1][maxMove - 1] % mod);
                    int up = (dp[i - 1][j][maxMove - 1] % mod);
                    int down = (dp[i + 1][j][maxMove - 1] % mod);
                    dp[i][j][maxMove] = ((left + right) % mod + (up + down) % mod) % mod;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
    // Space Optimization
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        // return solve(startRow, startColumn, m, n, maxMove);
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        // return solveMem(startRow, startColumn, m, n, maxMove, dp);
        return solveTab(m, n, maxMove, startRow, startColumn);
    }
};
int main()
{
    Solution s;
    int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
    cout << "Result: " << s.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/out-of-boundary-paths/

Youtube: https://www.youtube.com/watch?v=YH-ZG0q--DQ

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

576. Out of Boundary Paths

There is an m x n grid with a ball. The ball is initially at the
position [startRow, startColumn]. You are allowed to move the ball
to one of the four adjacent cells in the grid (possibly out of the
grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the
number of paths to move the ball out of the grid boundary. Since the
answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

*/