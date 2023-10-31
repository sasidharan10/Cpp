#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(n*m*4)

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ((i == 0 || i == row - 1 || j == 0 || j == col - 1) && grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int nRow[]{-1, 0, 1, 0};
            int nCol[]{0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newRow = r + nRow[i];
                int newCol = c + nCol[i];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && vis[newRow][newCol] != 1 && grid[newRow][newCol] == 1)
                {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if ((i != 0 || i != row - 1 || j != 0 || j != col - 1) && grid[i][j] == 1 && vis[i][j] != 1)
                {
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
    vector<vector<int>> v{{0, 0, 0, 0},
                          {1, 0, 1, 0},
                          {0, 1, 1, 0},
                          {0, 0, 0, 0}};
    cout << "Number of land cells in which we cannot walk off the boundary: " << s.numEnclaves(v);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

leetcode: https://leetcode.com/problems/number-of-enclaves/description/

Youtube: https://www.youtube.com/watch?v=rxKcepXQgU4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=15

algorithm:

*/