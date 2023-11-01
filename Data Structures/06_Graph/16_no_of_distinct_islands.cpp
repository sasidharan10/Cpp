#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int r, int c, int baseRow, int baseCol, vector<pair<int, int>> &island, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int row = grid.size();
        int col = grid[0].size();
        vis[r][c] = 1;
        island.push_back({abs(r - baseRow), abs(c - baseCol)});
        int nRow[]{-1, 0, 1, 0};
        int nCol[]{0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = r + nRow[i];
            int newCol = c + nCol[i];
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && vis[newRow][newCol] != 1 && grid[newRow][newCol] == 1)
            {
                dfs(newRow, newCol, baseRow, baseCol, island, grid, vis);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<pair<int, int>> island;
        set<vector<pair<int, int>>> distinctIsland;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (vis[i][j] != 1 && grid[i][j] == 1)
                {
                    dfs(i, j, i, j, island, grid, vis);
                    distinctIsland.insert(island);
                    island.clear();
                }
            }
        }
        return distinctIsland.size();
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v{{1, 1, 0, 1, 1},
                          {1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1},
                          {1, 1, 0, 1, 1}};
    cout << "Number of Distinct Island: " << s.countDistinctIslands(v);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

leetcode:

Youtube:

algorithm:

*/