#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dRow[4]{-1, 0, 1, 0};
    int dCol[4]{0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &vis)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] == 0 && vis[newRow][newCol] != 1)
            {
                dfs(newRow, newCol, matrix, vis);
            }
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        // TC: O(n*m*9)
        // SC: O(n*m*9)

        int n = grid.size();
        int m = grid[0].size();
        int row = n * 3;
        int col = m * 3;
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        int r = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '/')
                {
                    matrix[r][c + 2] = 1;
                    matrix[r + 1][c + 1] = 1;
                    matrix[r + 2][c] = 1;
                }
                else if (grid[i][j] == '\\')
                {
                    matrix[r][c] = 1;
                    matrix[r + 1][c + 1] = 1;
                    matrix[r + 2][c + 2] = 1;
                }
                c += 3;
            }
            r += 3;
            c = 0;
        }

        int cnt = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0 && vis[i][j] != 1)
                {
                    dfs(i, j, matrix, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    // vector<string> grid{"/\\", "\\/"};
    vector<string> grid{"//", "/ "};
    cout << "Result: " << s.regionsBySlashes(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/regions-cut-by-slashes

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

959. Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or
blank space ' '. These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.

*/

/*
************* Java Code **************

    public static int[] dRow={-1, 0, 1, 0};
    public static int[] dCol={0, 1, 0, -1};
    public static void dfs(int row, int col, int[][] matrix, int[][] vis)
    {
        int n = matrix.length;
        int m = matrix[0].length;
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] == 0 && vis[newRow][newCol] != 1)
            {
                dfs(newRow, newCol, matrix, vis);
            }
        }
    }
    public static int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int m = grid[0].length();

        int row = n * 3;
        int col = m * 3;
        int[][] matrix = new int[row][col];
        int r = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i].charAt(j) == '/')
                {
                    matrix[r][c + 2] = 1;
                    matrix[r + 1][c + 1] = 1;
                    matrix[r + 2][c] = 1;
                }
                else if (grid[i].charAt(j) == '\\')
                {
                    matrix[r][c] = 1;
                    matrix[r + 1][c + 1] = 1;
                    matrix[r + 2][c + 2] = 1;
                }
                c += 3;
            }
            r += 3;
            c = 0;
        }

        int cnt = 0;
        int[][] vis = new int[row][col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0 && vis[i][j] != 1)
                {
                    dfs(i, j, matrix, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }

*/