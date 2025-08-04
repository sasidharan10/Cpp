#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dRow{-1, 0, 1, 0};
    vector<int> dCol{0, 1, 0, -1};
    bool dfs(int row, int col, int parentRow, int parentCol, char parent, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            if (newCol >= 0 && newCol < m && newRow >= 0 && newRow < n && !(newRow == parentRow && newCol == parentCol) && grid[newRow][newCol] == parent && vis[newRow][newCol] == 1)
                return true;
            else if (newCol >= 0 && newCol < m && newRow >= 0 && newRow < n && !(newRow == parentRow && newCol == parentCol) && grid[newRow][newCol] == parent && !vis[newRow][newCol])
            {
                if (dfs(newRow, newCol, row, col, grid[row][col], grid, vis))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    if (dfs(i, j, -1, -1, grid[i][j], grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> grid{{'c', 'c', 'c', 'a'}, {'c', 'd', 'c', 'c'}, {'c', 'c', 'e', 'c'}, {'f', 'c', 'c', 'c'}};
    cout << "Contains Cycle?: " << s.containsCycle(grid);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

Youtube: https://www.youtube.com/watch?v=hy6aAittY9Q

algorithm:

*/