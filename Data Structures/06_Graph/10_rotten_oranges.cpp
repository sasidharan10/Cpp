#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int cntFresh = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        int cnt = 0;
        int maxTime = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int tempRow = q.front().first.first;
            int tempCol = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxTime = max(maxTime, time);

            for (int i = 0; i < 4; i++)
            {
                int nRow = tempRow + dRow[i];
                int nCol = tempCol + dCol[i];

                if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col && grid[nRow][nCol] == 1 && vis[nRow][nCol] != 2)
                {
                    cnt++;
                    vis[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, time + 1});
                }
            }
        }
        if (cntFresh != cnt)
            return -1;
        return maxTime;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> v{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    cout << "Before changing color: \n";
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "Time taken to rot all oranges: " << s.orangesRotting(v) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

leetcode: https://leetcode.com/problems/rotting-oranges/

Youtube: https://www.youtube.com/watch?v=yf3oUhkvqA0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=10

algorithm:

*/
