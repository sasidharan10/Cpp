#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // DFS helper to calculate perimeter contribution from a land cell
    int dfs(int row, int col, int n, int m, vector<vector<int>> &grid)
    {
        // If out of bounds, it contributes 1 to the perimeter
        if (row < 0 || row >= n || col < 0 || col >= m)
            return 1;

        // If current cell is water (0), it's a boundary → contributes 1 to perimeter
        if (grid[row][col] == 0)
            return 1;

        // If already visited, no perimeter contribution
        if (grid[row][col] == -1)
            return 0;

        // Mark the current land cell as visited
        grid[row][col] = -1;

        // Direction vectors: up, right, down, left
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};

        int res = 0;

        // Explore all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Add perimeter contribution from the adjacent cell
            res += dfs(newRow, newCol, n, m, grid);
        }
        return res;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        // Time Complexity: O(n * m) – visit each land cell once
        // Space Complexity: O(n * m) – due to recursion stack in worst case

        int n = grid.size();
        int m = grid[0].size();

        // Find the first land cell and start DFS from there
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(i, j, n, m, grid);
                }
            }
        }
        // If no land found (shouldn't happen per problem constraints)
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << "Result: " << s.islandPerimeter(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/island-perimeter/

Youtube: https://www.youtube.com/watch?v=fISIuAFRM2s

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

463. Island Perimeter

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0
represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by
water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.

*/

/*
************* Java Code **************

public int islandPerimeter(int[][] grid) {
    // TC: O(n*m)
    // SC: O(n*m)

    int n = grid.length;
    int m = grid[0].length;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return dfs(i, j, n, m, grid);
            }
        }
    }
    return -1;
}

private int dfs(int row, int col, int n, int m, int[][] grid) {
    if (row < 0 || row >= n || col < 0 || col >= m)
        return 1;
    if (grid[row][col] == 0)
        return 1;
    if (grid[row][col] == -1)
        return 0;

    grid[row][col] = -1;
    int[] dRow = {-1, 0, 1, 0};
    int[] dCol = {0, 1, 0, -1};
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];
        res += dfs(newRow, newCol, n, m, grid);
    }
    return res;
}

*/