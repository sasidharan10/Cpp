#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<vector<int>> ans(row, vector<int>(col, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            ans[r][c] = steps;
            q.pop();

            int dRow[]{-1, 0, 1, 0};
            int dCol[]{0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !vis[newRow][newCol])
                {
                    q.push({{newRow, newCol}, steps + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> v{{1, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    vector<vector<int>> ans = s.nearest(v);
    cout << "Distance matrix : \n";
    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

leetcode:

Youtube: https://www.youtube.com/watch?v=edXdVwkYHF8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=13

algorithm:

*/
