#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &mat, vector<vector<int>> &vis)
    {
        int row = mat.size();
        int col = mat[0].size();
        vis[r][c] = 1;
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !vis[newRow][newCol] && mat[newRow][newCol] == 'O')
            {
                dfs(newRow, newCol, mat, vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, mat, vis);
            }
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1])
            {
                dfs(i, m - 1, mat, vis);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O' && !vis[0][i])
            {
                dfs(0, i, mat, vis);
            }
            if (mat[n - 1][i] == 'O' && !vis[n - 1][i])
            {
                dfs(n - 1, i, mat, vis);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};
int main()
{
    Solution s;
    int n = 5;
    int m = 4;
    vector<vector<char>> v{{'X', 'X', 'X', 'X'},
                           {'X', 'O', 'X', 'X'},
                           {'X', 'O', 'O', 'X'},
                           {'X', 'O', 'X', 'X'},
                           {'X', 'X', 'O', 'O'}};
    vector<vector<char>> ans = s.fill(n, m, v);
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

link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

leetcode:

Youtube: https://www.youtube.com/watch?v=BtdgAys4yMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=14

algorithm:

*/
