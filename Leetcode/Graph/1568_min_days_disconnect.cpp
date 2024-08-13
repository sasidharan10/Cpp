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

- 

- Optimal Approach:

- self explanatory

*/

/*






*/

/*
************* Java Code **************



*/