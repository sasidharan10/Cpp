#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    // Recursion
    int minFallingPathSumRecur(int row, int col, vector<vector<int>> &grid)
    {
        // TC: O(n^n * n)
        // SC: O(m)

        if (row == n)
            return 0;
        int mini = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (j != col)
                mini = min(mini, minFallingPathSumRecur(row + 1, j, grid));
        }
        return mini + grid[row][col];
    }
    // Memoization
    int minFallingPathSumMem(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // TC: O(n*m*m)
        // SC: O(n*m) + O(m) Stack space

        if (row == n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int mini = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (j != col)
                mini = min(mini, minFallingPathSumMem(row + 1, j, grid, dp));
        }
        return dp[row][col] = mini + grid[row][col];
    }
    // Tabulation
    int minFallingPathSumTab(vector<vector<int>> &grid)
    {
        // TC: O(n*m*m)
        // SC: O(n*m)

        int n = grid.size();
        int m = grid[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int j = 0; j < m; j++)
        {
            dp[n - 1][j] = grid[n - 1][j];
        }
        int prev = 0;
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col < m; col++)
            {
                mini = INT_MAX;
                for (int j = 0; j < m; j++)
                {
                    if (j != col)
                        mini = min(mini, dp[row + 1][j]);
                }
                dp[row][col] = grid[row][col] + mini;
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
    // Space Optimization
    int minFallingPathSumSpc(vector<vector<int>> &grid)
    {
        // TC: O(n*m*m)
        // SC: O(m)

        int n = grid.size();
        int m = grid[0].size();
        int mini = INT_MAX;
        vector<int> ahead(m, INT_MAX);
        for (int j = 0; j < m; j++)
        {
            ahead[j] = grid[n - 1][j];
        }
        int prev = 0;
        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> cur(m, INT_MAX);
            for (int col = 0; col < m; col++)
            {
                mini = INT_MAX;
                for (int j = 0; j < m; j++)
                {
                    if (j != col)
                        mini = min(mini, ahead[j]);
                }
                cur[col] = grid[row][col] + mini;
            }
            ahead = cur;
        }
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, ahead[j]);
        }
        return ans;
    }

    // More Space Optimization
    int minFallingPathSumMoreSpc(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(m)

        int n = grid.size();
        int m = grid[0].size();
        vector<int> ahead(m, INT_MAX);
        int nextMinCol1 = -1;
        int nextMinCol2 = -1;
        for (int j = 0; j < m; j++)
        {
            ahead[j] = grid[n - 1][j];
            if (nextMinCol1 == -1 || grid[n - 1][j] <= grid[n - 1][nextMinCol1])
            {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = j;
            }
            else if (nextMinCol2 == -1 || grid[n - 1][j] <= grid[n - 1][nextMinCol2])
                nextMinCol2 = j;
        }
        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> cur(m, INT_MAX);
            int minCol1 = -1;
            int minCol2 = -1;
            for (int col = 0; col < m; col++)
            {
                if (col != nextMinCol1)
                    cur[col] = grid[row][col] + ahead[nextMinCol1];
                else
                    cur[col] = grid[row][col] + ahead[nextMinCol2];

                if (minCol1 == -1 || cur[col] <= cur[minCol1])
                {
                    minCol2 = minCol1;
                    minCol1 = col;
                }
                else if (minCol2 == -1 || cur[col] <= cur[minCol2])
                    minCol2 = col;
            }
            ahead = cur;
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }
        // int ans = INT_MAX;
        // for (int j = 0; j < m; j++)
        // {
        //     ans = min(ans, ahead[j]);
        // }
        // return ans;
        return ahead[nextMinCol1];
    }

    int minFallingPathSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int j = 0; j < m; j++)
        {
            mini = min(mini, grid[0][j] + minFallingPathSumRecur(1, j, grid));
            // mini = min(mini, minFallingPathSumMem(0, j, grid, dp));
        }
        return mini;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> nums{{-73, 61, 43, -48, -36}, {3, 30, 27, 57, 10}, {96, -76, 84, 59, -15}, {5, -49, 76, 31, -7}, {97, 91, 61, -46, 67}};
    // cout << "Result: " << s.minFallingPathSum(nums) << endl;
    // cout << "Result: " << s.minFallingPathSumTab(nums) << endl;
    // cout << "Result: " << s.minFallingPathSumSpc(nums) << endl;
    cout << "Result: " << s.minFallingPathSumMoreSpc(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-falling-path-sum-ii/

Youtube: https://www.youtube.com/watch?v=rpW1qKAs4V4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Minimum%20Falling%20Path%20Sum%20II.cpp

algorithm:

- DP

*/

/*

1289. Minimum Falling Path Sum II

Given an n x n integer matrix grid, return the minimum sum of a
falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element
from each row of grid such that no two elements chosen in adjacent rows are in the same column.

Example 1:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:

Input: grid = [[7]]
Output: 7

*/

/*
************* Java Code **************

public static int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[] ahead = new int[m];
        Arrays.fill(ahead, Integer.MAX_VALUE);
        int nextMinCol1 = -1;
        int nextMinCol2 = -1;
        for (int j = 0; j < m; j++) {
            ahead[j] = grid[n - 1][j];
            if (nextMinCol1 == -1 || grid[n - 1][j] <= grid[n - 1][nextMinCol1]) {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = j;
            } else if (nextMinCol2 == -1 || grid[n - 1][j] <= grid[n - 1][nextMinCol2])
                nextMinCol2 = j;
        }
        for (int row = n - 2; row >= 0; row--) {
            int[] cur = new int[m];
            Arrays.fill(cur, Integer.MAX_VALUE);
            int minCol1 = -1;
            int minCol2 = -1;
            for (int col = 0; col < m; col++) {
                if (col != nextMinCol1)
                    cur[col] = grid[row][col] + ahead[nextMinCol1];
                else
                    cur[col] = grid[row][col] + ahead[nextMinCol2];

                if (minCol1 == -1 || cur[col] <= cur[minCol1]) {
                    minCol2 = minCol1;
                    minCol1 = col;
                } else if (minCol2 == -1 || cur[col] <= cur[minCol2])
                    minCol2 = col;
            }
            ahead = cur;
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }
        return ahead[nextMinCol1];
    }

*/