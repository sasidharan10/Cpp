#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solveRecur(int i, int j, int n, vector<vector<int>> &matrix)
    {
        if (i >= n || j < 0 || j >= n)
            return 1e9;
        if (i == n - 1)
            return matrix[i][j];
        int ans = matrix[i][j];
        int left = 1e9, right = 1e9, down = 1e9;
        left = matrix[i][j] + solveRecur(i + 1, j - 1, n, matrix);
        right = matrix[i][j] + solveRecur(i + 1, j + 1, n, matrix);
        down = matrix[i][j] + solveRecur(i + 1, j, n, matrix);
        return min({left, down, right});
    }
    // Memoization
    int solveMem(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i >= n || j < 0 || j >= n)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1)
            return matrix[i][j];
        int left = 1e9, right = 1e9, down = 1e9;
        left = matrix[i][j] + solveMem(i + 1, j - 1, n, matrix, dp);
        right = matrix[i][j] + solveMem(i + 1, j + 1, n, matrix, dp);
        down = matrix[i][j] + solveMem(i + 1, j, n, matrix, dp);
        return dp[i][j] = min({left, down, right});
    }
    // Tabulation
    int solveTab(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = 1e9, right = 1e9, down = 1e9;
                if (j >= 1)
                    left = matrix[i][j] + dp[i - 1][j - 1];
                if (j < n - 1)
                    right = matrix[i][j] + dp[i - 1][j + 1];
                down = matrix[i][j] + dp[i - 1][j];
                dp[i][j] = min({left, down, right});
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
    // Space Optimization
    int solveSpc(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n + 1, 0);
        for (int j = 0; j < n; j++)
        {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> cur(n + 1, 0);
            for (int j = 0; j < n; j++)
            {
                int left = 1e9, right = 1e9, down = 1e9;
                if (j >= 1)
                    left = matrix[i][j] + prev[j - 1];
                if (j < n - 1)
                    right = matrix[i][j] + prev[j + 1];
                down = matrix[i][j] + prev[j];
                cur[j] = min({left, down, right});
            }
            prev = cur;
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            // int temp = solveRecur(0, i, n, matrix);
            int temp = solveMem(0, i, n, matrix, dp);
            mini = min(mini, temp);
        }
        return mini;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << "Minimum Falling Path Sum: ";
    // cout << s.minFallingPathSum(nums) << endl;
    // cout << s.solveTab(nums) << endl;
    cout << s.solveSpc(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-falling-path-sum/

Youtube:

algorithm:

- DP

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum
sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses
the element in the next row that is either directly below or diagonally
left/right. Specifically, the next element from position (row, col)
will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

*/