#include <bits/stdc++.h>
using namespace std;
// Recursion
int mazeObstaclesRecur(int i, int j, vector<vector<int>> &mat)
{
    // TC: O(2^m*n)
    // SC: O(n-1 + m-1)

    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = mazeObstaclesRecur(i - 1, j, mat);
    int left = mazeObstaclesRecur(i, j - 1, mat);
    return up + left;
}
// Memoization
int mazeObstaclesMem(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    // TC: O(n*m)
    // SC: O(n-1 + m-1) + O(n*m)
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = mazeObstaclesMem(i - 1, j, mat, dp);
    int left = mazeObstaclesMem(i, j - 1, mat, dp);
    return dp[i][j] = up + left;
}
int mod = (int)(1e9 + 7);
// Tabulation
int mazeObstaclesTab(int n, int m, vector<vector<int>> &mat)
{
    // TC: O(n*m)
    // SC: O(n*m)

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            else if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = (up + left)%mod;
        }
    }
    return dp[n - 1][m - 1];
}
// Space Optimization
int mazeObstaclesSpc(int n, int m, vector<vector<int>> &mat)
{
    // TC: O(n*m)
    // SC: O(n)
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            else if (mat[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = (up + left)%mod;
        }
        prev = temp;
    }
    return prev[m - 1];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // return mazeObstaclesRecur(n - 1, m - 1, mat);
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return mazeObstaclesMem(n - 1, m - 1, mat, dp);
    // return uniquePathsTab(m, n);
    return mazeObstaclesSpc(n, m, mat);
}
int main()
{
    int n = 2;
    int m = 2;
    vector<vector<int>> mat{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << "Total possible paths: " << mazeObstacles(n, m, mat);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maze-obstacles_977241

leetcode:

Youtube: https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10

algorithm:

*/