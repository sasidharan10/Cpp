#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solveRecur(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
    {
        // TC: O(3 ^ n * 3 ^ n)
        // SC: O(n)

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        int maxi = 0;
        for (int col1 = -1; col1 <= 1; col1++)
        {
            for (int col2 = -1; col2 <= 1; col2++)
            {
                int newRow = i + 1;
                int newCol1 = j1 + col1;
                int newCol2 = j2 + col2;

                if (newRow >= 0 && newRow < n && newCol1 >= 0 && newCol1 < m && newCol2 >= 0 && newCol2 < m)
                {
                    int temp = 0;
                    if (j1 == j2)
                        temp = grid[i][j1];
                    else
                        temp = grid[i][j1] + grid[i][j2];

                    maxi = max(maxi, temp + solveRecur(newRow, newCol1, newCol2, n, m, grid));
                }
            }
        }
        return maxi;
    }
    // Memoization
    int solveMem(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        // TC: O(n * m * m) * 9
        // SC: O(n * m * m) + O(n)

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = 0;
        for (int col1 = -1; col1 <= 1; col1++)
        {
            for (int col2 = -1; col2 <= 1; col2++)
            {
                int newRow = i + 1;
                int newCol1 = j1 + col1;
                int newCol2 = j2 + col2;

                if (newRow >= 0 && newRow < n && newCol1 >= 0 && newCol1 < m && newCol2 >= 0 && newCol2 < m)
                {
                    int temp = 0;
                    if (j1 == j2)
                        temp = grid[i][j1];
                    else
                        temp = grid[i][j1] + grid[i][j2];

                    maxi = max(maxi, temp + solveMem(newRow, newCol1, newCol2, n, m, grid, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    // Tabulation
    int solveTab(vector<vector<int>> &grid)
    {
        // TC: O(n * m * m) * 9
        // SC: O(n * m * m)

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = 0;
                    for (int col1 = -1; col1 <= 1; col1++)
                    {
                        for (int col2 = -1; col2 <= 1; col2++)
                        {
                            int newRow = i + 1;
                            int newCol1 = j1 + col1;
                            int newCol2 = j2 + col2;

                            if (newRow >= 0 && newRow < n && newCol1 >= 0 && newCol1 < m && newCol2 >= 0 && newCol2 < m)
                            {
                                int temp = 0;
                                if (j1 == j2)
                                    temp = grid[i][j1];
                                else
                                    temp = grid[i][j1] + grid[i][j2];

                                maxi = max(maxi, temp + dp[newRow][newCol1][newCol2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
    // Space Optimization
    int solveSpc(vector<vector<int>> &grid)
    {
        // TC: O(n * m * m) * 9
        // SC: O(m * m)

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev(m + 1, vector<int>(m + 1, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    prev[j1][j2] = grid[n - 1][j1];
                else
                    prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<vector<int>> cur(m + 1, vector<int>(m + 1, 0));
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = 0;

                    for (int col1 = -1; col1 <= 1; col1++)
                    {
                        for (int col2 = -1; col2 <= 1; col2++)
                        {
                            int newRow = i + 1;
                            int newCol1 = j1 + col1;
                            int newCol2 = j2 + col2;

                            if (newRow >= 0 && newRow < n && newCol1 >= 0 && newCol1 < m && newCol2 >= 0 && newCol2 < m)
                            {
                                int temp = 0;
                                if (j1 == j2)
                                    temp = grid[i][j1];
                                else
                                    temp = grid[i][j1] + grid[i][j2];

                                maxi = max(maxi, temp + prev[newCol1][newCol2]);
                            }
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            prev = cur;
        }
        return prev[0][m - 1];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // return solveRecur(0, 0, m - 1, n, m, grid);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        // return solveMem(0, 0, m - 1, n, m, grid, dp);
        // return solveTab(grid);
        return solveSpc(grid);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    cout << "Max Cherry picked by both robots: " << s.cherryPickup(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/cherry-pickup-ii

Youtube: https://youtu.be/QGfn7JeXK54

algorithm:

tuf: https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1463. Cherry Pickup II

You are given a rows x cols matrix grid representing a field of cherries
where grid[i][j] represents the number of cherries that you can
collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both
robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

*/