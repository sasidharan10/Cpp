#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    int dRow[4]{-1, 0, 1, 0};
    int dCol[4]{0, 1, 0, -1};
    int dfs(int row, int col, vector<vector<int>> &grid)
    {
        if (row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == 0)
            return 0;
        int temp = grid[row][col];
        grid[row][col] = 0;
        int maxi = 0;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            maxi = max(maxi, dfs(newRow, newCol, grid));
        }
        grid[row][col] = temp;
        return maxi + temp;
    }
    
    // DFS + Backtrtacking
    int getMaximumGold(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                maxi = max(maxi, dfs(i, j, grid));
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << "Result: " << s.getMaximumGold(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-with-maximum-gold/

Youtube: https://www.youtube.com/watch?v=qlgeXDM1z7A

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Path%20with%20Maximum%20Gold.cpp

algorithm:

- Optimal Approach:

- DFS + Backtracking.
- We have to find a path with max sum.
- Each cell should be visited once, and should not visit 0's.
- any valid cell cab be starting point.
- Hence we iterate through every cell, and try it as a starting cell.
- Then we do dfs traversal, and find max sum in all 4 directions.
- Once traversal completed, we unmark the visted cell, hence back tracking.

*/

/*

1219. Path with Maximum Gold

In a gold mine grid of size m x n, each cell in this mine has an integer representing
the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

*/

/*
************* Java Code **************

public static int n, m;
    public static int[] dRow = { -1, 0, 1, 0 };
    public static int[] dCol = { 0, 1, 0, -1 };

    public static int dfs(int row, int col, int[][] grid) {
        if (row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == 0)
            return 0;
        int temp = grid[row][col];
        grid[row][col] = 0;
        int maxi = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            maxi = Math.max(maxi, dfs(newRow, newCol, grid));
        }
        grid[row][col] = temp;
        return maxi + temp;
    }

    public static int getMaximumGold(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = Math.max(maxi, dfs(i, j, grid));
            }
        }
        return maxi;
    }

*/