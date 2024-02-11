#include <bits/stdc++.h>
using namespace std;
// Recursion
int maximumChocolatesRecur(int i, int j1, int j2, vector<vector<int>> &grid)
{
    // TC: O(3 ^ n * 3 ^ n)
    // SC: O(n)

    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += maximumChocolatesRecur(i + 1, j1 + dj1, j2 + dj2, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
// Memoization
int maximumChocolatesMem(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // TC: O(n * m * m) * 9
    // SC: O(n * m * m) + O(n)

    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += maximumChocolatesMem(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
// Tabulation
int maximumChocolatesTab(int n, int m, vector<vector<int>> &grid)
{
    // TC: O(n * m * m) * 9
    // SC: O(n * m * m)

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
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
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
// Space Optimization
int maximumChocolatesSpc(int n, int m, vector<vector<int>> &grid)
{
    // TC: O(n * m * m) * 9
    // SC: O(m * m)
    
    vector<vector<int>> prev(m, vector<int>(m, 0));
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
        vector<vector<int>> cur(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += prev[j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        prev = cur;
    }
    return prev[0][m - 1];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // return maximumChocolatesRecur(0, 0, c - 1, grid);
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return maximumChocolatesMem(0, 0, c - 1, grid, dp);
    // return maximumChocolatesTab(r, c, grid);
    return maximumChocolatesSpc(r, c, grid);
}
int main()
{
    vector<vector<int>> grid{{2, 3, 1, 2},
                             {3, 4, 2, 2},
                             {5, 6, 3, 5}};
    int r = 3;
    int c = 4;
    cout << "Maximum chocolate picked by both: " << maximumChocolates(r, c, grid);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885

leetcode: https://leetcode.com/problems/cherry-pickup-ii

Youtube: https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16

algorithm:

tuf: https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/

*/