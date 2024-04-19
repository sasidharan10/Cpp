#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int row, col;
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        int nRow[]{-1, 0, 1, 0};
        int nCol[]{0, 1, 0, -1};
        while (!q.empty())
        {
            int tempRow = q.front().first;
            int tempCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int drow = tempRow + nRow[i];
                int dcol = tempCol + nCol[i];
                if (drow >= 0 && drow < row && dcol >= 0 && dcol < col && !vis[drow][dcol] && grid[drow][dcol] == '1')
                {
                    q.push({drow, dcol});
                    vis[drow][dcol] = 1;
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == '0' || vis[r][c] == 1)
            return;
        vis[r][c] = 1;
        dfs(r - 1, c, vis, grid);
        dfs(r, c + 1, vis, grid);
        dfs(r + 1, c, vis, grid);
        dfs(r, c - 1, vis, grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // TC: O(n*m)
        // SC: O(n*m)

        row = grid.size();
        col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    // bfs(i, j, vis, grid);
                    dfs(i, j, vis, grid);
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
    int n = 3;
    vector<vector<char>> v{{'1', '1', '0', '0', '0'},
                           {'1', '1', '0', '0', '0'},
                           {'0', '0', '1', '0', '0'},
                           {'0', '0', '0', '1', '1'}};
    cout << "No of Islands: " << s.numIslands(v);
    return 0;
}

/*



algorithm:

*/

/*

link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

leetcode: https://leetcode.com/problems/number-of-islands/

Youtube: https://www.youtube.com/watch?v=muncqlKJrH0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number%20of%20Islands.cpp

algorithm:

- Just do a simple bfs or dfs, until all the adjacent cells are visited on that  particular island.
- We do this until all cells are visited.
- In this way, each time we visit a cell, that island will be visited.
- hence the no of times, we mark the island is the no of island present in the grid.

*/

/*

200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

/*
************* Java Code **************

public static class Pair {
        int first;
        int second;

        Pair() {
        }

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static int[][] vis;

    public static void bfs(int r, int c, char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        Queue<Pair> que = new LinkedList<>();
        que.offer(new Pair(r, c));
        vis[r][c] = 1;
        int[] nRow = { -1, 0, 1, 0 };
        int[] nCol = { 0, 1, 0, -1 };
        while (!que.isEmpty()) {
            int tempRow = que.peek().first;
            int tempCol = que.peek().second;
            que.poll();

            for (int i = 0; i < 4; i++) {
                int drow = tempRow + nRow[i];
                int dcol = tempCol + nCol[i];
                if (drow >= 0 && drow < row && dcol >= 0 && dcol < col && vis[drow][dcol] == 0
                        && grid[drow][dcol] == '1') {
                    que.offer(new Pair(drow, dcol));
                    vis[drow][dcol] = 1;
                }
            }
        }
    }

    public static int numIslands(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        vis = new int[row][col];

        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }

*/