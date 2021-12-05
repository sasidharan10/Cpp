#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void solve(vector<vector<int>> v, int i, int j, int n, string move, vector<string> &ans, vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    // Down
    if (i + 1 < n && !vis[i + 1][j] && v[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(v, i + 1, j, n, move + "D", ans, vis);
        vis[i][j] = 0;
    }
    // Left
    if (j - 1 >= 0 && !vis[i][j - 1] && v[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        solve(v, i, j - 1, n, move + "L", ans, vis);
        vis[i][j] = 0;
    }
    // Right
    if (j + 1 < n && !vis[i][j + 1] && v[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        solve(v, i, j + 1, n, move + "R", ans, vis);
        vis[i][j] = 0;
    }
    // Up
    if (i - 1 >= 0 && !vis[i - 1][j] && v[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(v, i - 1, j, n, move + "U", ans, vis);
        vis[i][j] = 0;
    }
}

void solve2(vector<vector<int>> v, int i, int j, int n, string move, vector<string> &ans, vector<vector<int>> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string str = "DLRU";
    for (int index = 0; index < 4; index++)
    {
        int nexti = i + di[index];
        int nextj = j + dj[index];
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !vis[nexti][nextj] && v[i][j] == 1)
        {
            vis[i][j] = 1;
            solve2(v, nexti, nextj, n, move + str[index], ans, vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

void ratMaze(vector<vector<int>> v, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (v[0][0] == 1)
        solve(v, 0, 0, n, "", ans, vis);
    cout << "Solution 1 : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    ans.clear();

    int di[4]{1, 0, 0, -1};
    int dj[4]{0, -1, 1, 0};
    solve2(v, 0, 0, n, "", ans, vis, di, dj);
    cout << "Solution 2 : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    // vector<vector<int>> v{{1, 0, 0, 0},
    //                       {1, 1, 0, 1},
    //                       {1, 1, 0, 0},
    //                       {0, 1, 1, 1}};
    vector<vector<int>> v{{1, 1},
                          {1, 1}};           
    int n = v[0].size();
    ratMaze(v, n);
    return 0;
}