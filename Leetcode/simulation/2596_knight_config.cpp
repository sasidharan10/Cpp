#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(int i, int j, int n, int cnt, vector<vector<int>> &grid)
    {
        // TC: O(n*n)
        // SC: only stack space = O(n*n)
        
        if (cnt == n * n)
            return true;
        int row = -1, col = -1;
        // top left
        if (i - 2 >= 0 && j - 1 >= 0 && grid[i - 2][j - 1] == cnt)
        {
            row = i - 2;
            col = j - 1;
        }

        // top right
        if (i - 2 >= 0 && j + 1 < n && grid[i - 2][j + 1] == cnt)
        {
            row = i - 2;
            col = j + 1;
        }

        // right top
        if (i - 1 >= 0 && j + 2 < n && grid[i - 1][j + 2] == cnt)
        {
            row = i - 1;
            col = j + 2;
        }

        // right down
        if (i + 1 < n && j + 2 < n && grid[i + 1][j + 2] == cnt)
        {
            row = i + 1;
            col = j + 2;
        }

        // down right
        if (i + 2 < n && j + 1 < n && grid[i + 2][j + 1] == cnt)
        {
            row = i + 2;
            col = j + 1;
        }

        // down left
        if (i + 2 < n && j - 1 >= 0 && grid[i + 2][j - 1] == cnt)
        {
            row = i + 2;
            col = j - 1;
        }

        // left down
        if (i + 1 < n && j - 2 >= 0 && grid[i + 1][j - 2] == cnt)
        {
            row = i + 1;
            col = j - 2;
        }

        // left top
        if (i - 1 >= 0 && j - 2 >= 0 && grid[i - 1][j - 2] == cnt)
        {
            row = i - 1;
            col = j - 2;
        }

        if (row == -1)
            return false;
        return solve(row, col, n, cnt + 1, grid);
    }
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
            return false;
        int n = grid.size();
        return solve(0, 0, n, 1, grid);
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> grid{{0, 11, 16, 5, 20}, {17, 4, 19, 10, 15}, {12, 1, 8, 21, 6}, {3, 18, 23, 14, 9}, {24, 13, 2, 7, 22}};
    // vector<vector<int>> grid{{0,3,6},{5,8,1},{2,7,4}};
    vector<vector<int>> grid{{8, 3, 6}, {5, 0, 1}, {2, 7, 4}};
    cout << "Result: " << s.checkValidGrid(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/check-knight-tour-configuration/

Youtube:

algorithm:

- Its a DFS traversal
- Knight can only move in L shape and a knight has at most 8 moves
  from its position. 
- Hence from each cell, we check for all 8 moves of the knight
  and see if we have the (cell + 1) value. If yes, we move to that cell, and check 
  again for (cell + 1) value using those 8 moves.
- If not, return false. If cell == n*n, means we bisited all cells and all values
  are present in the matrix, hence we return true.
.
*/

/*

2596. Check Knight Tour Configuration

There is a knight on an n x n chessboard. In a valid configuration,
the knight starts at the top-left cell of the board and visits every
cell on the board exactly once.

You are given an n x n integer matrix grid consisting of distinct
integers from the range [0, n * n - 1] where grid[row][col] indicates
that the cell (row, col) is the grid[row][col]th cell that the knight
visited. The moves are 0-indexed.

Return true if grid represents a valid configuration of the knight's
 movements or false otherwise.

Note that a valid knight move consists of moving two squares vertically
and one square horizontally, or two squares horizontally and one square
vertically. The figure below illustrates all the possible eight moves
of a knight from some cell.

Example 1:

Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
Output: true
Explanation: The above diagram represents the grid. It can be
shown that it is a valid configuration.

Example 2:

Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
Output: false
Explanation: The above diagram represents the grid. The 8th move of the
knight is not valid considering its position after the 7th move.

*/