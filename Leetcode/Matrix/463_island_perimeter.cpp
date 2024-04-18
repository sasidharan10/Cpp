#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int peri;
    int n, m;
    // using BFS
    int islandPerimeter(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(n*m)
        
        peri = 0;
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    que.push({i, j});
                    grid[i][j] = -1;
                    break;
                }
            }
        }
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};

        while (!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] == 0)
                    peri++;
                else if (grid[newRow][newCol] == -1)
                    continue;
                else
                {
                    grid[newRow][newCol] = -1;
                    que.push({newRow, newCol});
                }
            }
        }
        return peri;
    }

    // using DFS
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        {
            peri++;
            return;
        }
        if (grid[i][j] == -1)
            return;
        grid[i][j] = -1;
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
    }
    int islandPerimete2(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(n*m) - stack space
        
        peri = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    return peri;
                }
            }
        }
        return peri;
    }

    // Iterative
    int islandPerimeter3(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(1)

        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    // top
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        res++;
                    // right
                    if (j + 1 >= m || grid[i][j + 1] == 0)
                        res++;
                    // bottom
                    if (i + 1 >= n || grid[i + 1][j] == 0)
                        res++;
                    // left
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        res++;
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << "Island Perimeter: " << s.islandPerimeter(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/island-perimeter/

Youtube: https://www.youtube.com/watch?v=O34v6f6s3lQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Island%20Perimeter.cpp

algorithm:

- Its given, there will be only 1 island in the grid. hence we find the grid[i][j]==1, and
  do a dfs or bfs traversal, to calculate the perimeter.
- At any valid cell, if its adjacent cells(4 directions) are invalid or '0', it means its
  a side of that island, hence we increment the peri.
- finally return the peri.

*/

/*

463. Island Perimeter

You are given row x col grid representing a map where grid[i][j] = 1 represents land
and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely
surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water
around the island. One cell is a square with side length 1. The grid is rectangular,
width and height don't exceed 100. Determine the perimeter of the island.

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

*/

/*
************* Java Code **************

public int islandPerimeter(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // top
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        res++;
                    // right
                    if (j + 1 >= m || grid[i][j + 1] == 0)
                        res++;
                    // bottom
                    if (i + 1 >= n || grid[i + 1][j] == 0)
                        res++;
                    // left
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        res++;
                }
            }
        }
        return res;
    }

*/