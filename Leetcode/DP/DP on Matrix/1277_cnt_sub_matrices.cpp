#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;

    // Returns the size of the largest square with top-left corner at (i,j)
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // Out of bounds
        if (i >= n || j >= m)
            return 0;

        // Can't form square if current cell is 0
        if (matrix[i][j] == 0)
            return 0;

        // Return cached result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Check squares formed by extending down, right, and diagonal
        int down = solve(i + 1, j, matrix, dp);
        int diag = solve(i + 1, j + 1, matrix, dp);
        int right = solve(i, j + 1, matrix, dp);

        // Current cell contributes 1 + minimum of the three directions
        return dp[i][j] = 1 + min({down, diag, right});
    }

    // Recursion + Memoization
    int countSquares2(vector<vector<int>> &matrix)
    {
        // TC: O(n * m)
        // SC: O(n * m)

        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int res = 0;
        // For every cell, if it's 1, add the number of squares ending at (i,j)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    res += solve(i, j, matrix, dp);
                }
            }
        }
        return res;
    }

    // Tabulation
    int countSquares(vector<vector<int>> &matrix)
    {
        // TC: O(n * m)
        // SC: O(n * m)

        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1)
                {
                    int up = dp[i - 1][j];
                    int diag = dp[i - 1][j - 1];
                    int left = dp[i][j - 1];

                    dp[i][j] = 1 + min({up, diag, left});
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{0, 1, 1, 1},
                             {1, 1, 1, 1},
                             {0, 1, 1, 1}};
    cout << "Result: " << s.countSquares(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-square-submatrices-with-all-ones

Youtube: https://www.youtube.com/watch?v=y3kdowdyNMM

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/DP%20on%20Grids/Count%20Square%20Submatrices%20with%20All%20Ones.cpp

algorithm:

- Better Approach:

- If a cell is 0, no square can start there → dp[i][j] = 0.
- If a cell is 1, largest square at (i,j) depends on right, down, and diagonal cells.
- Relation: dp[i][j] = 1 + min(down, right, diag).
- Each dp[i][j] also counts all smaller squares inside it.
- For every cell (i,j), add dp[i][j] to the result.
- Use memoization to avoid recomputation, ensuring each cell solved once.

- Optimal Approach:

- Create dp[i][j] = size of largest square ending at (i,j) (bottom-right corner).
- If matrix[i][j] == 0 → dp[i][j] = 0.
- If matrix[i][j] == 1 →
- If on first row/col → dp[i][j] = 1.
- Else → dp[i][j] = 1 + min(up, left, diag).
- Add dp[i][j] to result for every cell.
- Final result = total count of all square submatrices with ones.

*/

/*

1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

/*
************* Java Code **************

    public static int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp = new int[n][m];

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1) {
                    int up = dp[i - 1][j];
                    int diag = dp[i - 1][j - 1];
                    int left = dp[i][j - 1];

                    dp[i][j] = 1 + Math.min(up, Math.min(diag, left));
                }
                res += dp[i][j];
            }
        }
        return res;
    }

*/