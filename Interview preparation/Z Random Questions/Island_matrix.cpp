#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void markIsland(vector<vector<int>> &v, int x, int y, int row, int col)
{
    if (x < 0 || y < 0 || x >= row || y >= col || v[x][y] != 1)
        return;

    v[x][y] = 2;
    markIsland(v, x + 1, y, row, col);
    markIsland(v, x, y + 1, row, col);
    markIsland(v, x - 1, y, row, col);
    markIsland(v, x, y - 1, row, col);
    markIsland(v, x + 1, y + 1, row, col);
    markIsland(v, x - 1, y + 1, row, col);
    markIsland(v, x + 1, y - 1, row, col);
    markIsland(v, x - 1, y - 1, row, col);
}
int countIsland(vector<vector<int>> v)
{
    // Time  : O(row*col)
    // Space : O(row*col) if stack memory is taken into consideration

    int row = v.size();
    int col = v[0].size();
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (v[i][j] == 1)
            {
                count++;
                markIsland(v, i, j, row, col);
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> v = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};
    // int row = v.size();
    // int col = v[0].size();
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "No of Islands : " << countIsland(v);
    return 0;
}