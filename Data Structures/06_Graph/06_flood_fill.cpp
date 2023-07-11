#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void dfs(int sr, int sc, int iniColor, int newColor, vector<vector<int>> &temp, vector<vector<int>> image)
    {
        int row = image.size();
        int col = image[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        temp[sr][sc] = newColor;
        for (int i = 0; i < 4; i++)
        {
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];
            if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col && image[nRow][nCol] == iniColor &&
                temp[nRow][nCol] != newColor)
            {
                dfs(nRow, nCol, iniColor, newColor, temp, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> temp = image;
        int iniColor = image[sr][sc];
        dfs(sr, sc, iniColor, newColor, temp, image);
        return temp;
    }
};
int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> v{{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}};
    cout << "Before changing color: \n";
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    vector<vector<int>> ans = s.floodFill(v, 1, 1, 2);
    cout << "After changing color: \n";
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

link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

leetcode:

Youtube: https://www.youtube.com/watch?v=C-2_uSRli8o&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=10

algorithm:

*/
