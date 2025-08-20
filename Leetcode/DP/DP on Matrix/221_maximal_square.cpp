#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;

    // Returns the size of the largest square with top-left corner at (i,j)
    int solve(int i, int j, vector<vector<char>> &matrix, vector<vector<int>> &dp)
    {
        // TC: O(n * m)
        // SC: O(n * m)

        // Out of bounds
        if (i >= n || j >= m)
            return 0;

        // Can't form square if current cell is 0
        if (matrix[i][j] == '0')
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
    int maximalSquare2(vector<vector<char>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();

        int res = 0;
        // For every cell, if it's 1, find the max square size
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    res = max(res, solve(i, j, matrix, dp));
                }
            }
        }
        // return total 1's count from the largest square by multipling itself
        return res * res;
    }

    // Tabulation
    int maximalSquare(vector<vector<char>> &matrix)
    {
        // TC: O(n * m)
        // SC: O(n * m)
        
        n = matrix.size();
        m = matrix[0].size();

        int res = 0;
        // For every cell, if it's 1, find the max square size
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
                else if (matrix[i][j] == '1')
                {
                    int up = dp[i - 1][j];
                    int diag = dp[i - 1][j - 1];
                    int left = dp[i][j - 1];

                    dp[i][j] = 1 + min({up, diag, left});
                }
                res = max(res, dp[i][j]);
            }
        }
        // return total 1's count from the largest square by multipling itself
        return res * res;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    cout << "Result: " << s.maximalSquare(matrix) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximal-square/

Youtube: https://www.youtube.com/watch?v=y3kdowdyNMM
 
Code Link:

algorithm:

- Better Approach:

- If a cell is 0, no square can start there → dp[i][j] = 0.
- If a cell is 1, largest square at (i,j) depends on right, down, and diagonal cells.
- Relation: dp[i][j] = 1 + min(down, right, diag).
- Each dp[i][j] also counts all smaller squares inside it.
- For every cell (i,j), find the max size of square i.e, dp[i][j].
- Use memoization to avoid recomputation, ensuring each cell solved once.
- return res * res, which returns the total 1's present in the largest square.

- Optimal Approach:

- Create dp[i][j] = size of largest square ending at (i,j) (bottom-right corner).
- If matrix[i][j] == 0 → dp[i][j] = 0.
- If matrix[i][j] == 1 →
- If on first row/col → dp[i][j] = 1.
- Else → dp[i][j] = 1 + min(up, left, diag).
- find the max size of square i.e, dp[i][j].
- Final result = res * res, which returns the total 1's present in the largest square.

*/

/*

221. Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

*/

/*
************* Java Code **************

    public static int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp = new int[n][m];

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
                else if (matrix[i][j] == '1') {
                    int up = dp[i - 1][j];
                    int diag = dp[i - 1][j - 1];
                    int left = dp[i][j - 1];

                    dp[i][j] = 1 + Math.min(up, Math.min(diag, left));
                }
                res = Math.max(res, dp[i][j]);
            }
        }
        return res * res;
    }


*/