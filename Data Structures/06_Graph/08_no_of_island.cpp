#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        while (!q.empty())
        {
            int tempRow = q.front().first;
            int tempCol = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int drow = tempRow + i;
                    int dcol = tempCol + j;
                    if (drow >= 0 && drow < row && dcol >= 0 && dcol < col && !vis[drow][dcol] && grid[drow][dcol] == '1')
                    {
                        q.push({drow, dcol});
                        vis[drow][dcol] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
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
    vector<vector<char>> v{{'0', '1', '1', '1', '0', '0', '0'}, {'0', '0', '1', '1', '0', '1', '0'}};
    cout << "No of Islands: " << s.numIslands(v);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

leetcode: https://leetcode.com/problems/number-of-islands/

Youtube: https://www.youtube.com/watch?v=muncqlKJrH0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=8

algorithm:

*/
