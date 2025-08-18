#include <bits/stdc++.h>
using namespace std;
// Recursion
int uniquePathsRecur(int i, int j)
{
    // TC: O(2^m*n)
    // SC: O(n-1 + m-1)

    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = uniquePathsRecur(i - 1, j);
    int left = uniquePathsRecur(i, j - 1);
    return up + left;
}
// Memoization
int uniquePathsMem(int i, int j, vector<vector<int>> &dp)
{
    // TC: O(n*m)
    // SC: O(n-1 + m-1) + O(n*m)

    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = uniquePathsMem(i - 1, j, dp);
    int left = uniquePathsMem(i, j - 1, dp);
    return dp[i][j] = up + left;
}
// Tabulation
int uniquePathsTab(int m, int n)
{
    // TC: O(n*m)
    // SC: O(n*m)

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
// Space Optimization
int uniquePathsSpc(int m, int n)
{
    // TC: O(n*m)
    // SC: O(n)

    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = curr[j - 1];
            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[n - 1];
}
// formnula
int uniquePathsFormula(int m, int n)
{
    int N = m + n - 2;
    int r = n - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
    // https://www.youtube.com/watch?v=t_f0nwwdg5o
}
int uniquePaths(int m, int n)
{
    // return uniquePathsRecur(m - 1, n - 1);
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return uniquePathsMem(m - 1, n - 1, dp);
    // return uniquePathsTab(m, n);
    return uniquePathsSpc(m, n);
    // return uniquePathsFormula(m, n);
}
int main()
{
    int n = 2;
    int m = 2;
    cout << "Total unique paths: " << uniquePaths(m, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

leetcode: https://leetcode.com/problems/unique-paths/description/

Youtube: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

Code Link: 

algorithm: 

- Brute Force Approach:

- 

- Optimal Approach:

- self explanatory

*/

/*

62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach 
the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

1 <= m, n <= 100

*/

/*   
************* Java Code **************

    // Tabulation
    public static int uniquePathsTab(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

    // Space optimization
    public static int uniquePathsSpc(int m, int n) {
        int[] prev = new int[n];
        for (int i = 0; i < m; i++) {
            int[] curr = new int[n];
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n - 1];
    }

*/