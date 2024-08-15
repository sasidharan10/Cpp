#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dRow[4]{-1, 0, 1, 0};
    int dCol[4]{0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol] != 1)
            {
                dfs(newRow, newCol, grid, vis);
            }
        }
    }
    // Brute force
    int minDays(vector<vector<int>> &grid)
    {
        // TC: O(n*m*n*m)
        // SC: O(n*m)

        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 1)
                {
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        if (cnt == 0 || cnt > 1)
            return 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    grid[r][c] = 0;
                    cnt = 0;
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (grid[i][j] == 1 && visited[i][j] != 1)
                            {
                                dfs(i, j, grid, visited);
                                cnt++;
                            }
                        }
                    }
                    if (cnt == 0 || cnt > 1)
                        return 1;
                    grid[r][c] = 1;
                }
            }
        }
        return 2;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    // vector<vector<int>> nums{{1, 1}};
    // vector<vector<int>> nums{{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}};
    cout << "Result: " << s.minDays(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island

Youtube: https://www.youtube.com/watch?v=HCHpyAk1Ekw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Minimum%20Number%20of%20Days%20to%20Disconnect%20Island.cpp

algorithm:

- Brute Force Approach:

- As per the given problem, We should not have exactly 1 island. Either we can have 0 island or
  more than 1 islands. If we have exactly 1 island, then we have to disconnect the island into
  2 parts.
- To disconnect an island, we can change one grid of land into water per day.
- Hence we need t find the minimum no of days to disconnect the island.
- Note that, no matter how big the island is, we only need to change, at max, 2 grids, to disconnect the 
  any given island.
- So, first we check the no of islands in the given matrix. If its 0, or more 1, then return 0.
- If exactly 1 island exists, then we need to disconnect it.
- Now we apply brute force, to check, if we can disconnect an island, by change 1 grid.
- We try to change every single grid into 0, then apply BFS, or DFS, to find the no of islands
  after the change. If the island gets disconnected ,then we return 1.
- If its not poosible by changing 1 grid, then surely we can disconnect it using 2 grids, 
  hence we just return 2.

- Optimal Approach:

- Using tarjams algorithm.

*/

/*

1568. Minimum Number of Days to Disconnect Island

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An 
island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Example 1:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.

*/

/*
************* Java Code **************



*/