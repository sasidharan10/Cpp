#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<vector<int>> ans(row, vector<int>(col, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
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
    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> ans = s.updateMatrix(v);
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

leetcode: https://leetcode.com/problems/01-matrix/

Youtube: https://www.youtube.com/watch?v=edXdVwkYHF8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=13

algorithm:

*/
