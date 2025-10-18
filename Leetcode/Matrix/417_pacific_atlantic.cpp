#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    int n, m;
    bool topLeftCheck(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &vis)
    {
        if (r < 0 || c < 0)
            return true;
        if (vis[r][c])
            return false;

        vis[r][c] = true;
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};
        bool res = false;
        for (int i = 0; i < 4; i++)
        {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];
            if (newRow < 0 || newCol < 0)
                return true;
            if (newRow >= n || newCol >= m || heights[newRow][newCol] > heights[r][c])
                continue;
            else
                res |= topLeftCheck(newRow, newCol, heights, vis);
        }
        return res;
    }
    bool bottomRightCheck(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &vis)
    {
        if (r >= n || c >= m)
            return true;
        if (vis[r][c])
            return false;

        vis[r][c] = true;
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};
        bool res = false;
        for (int i = 0; i < 4; i++)
        {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];
            if (newRow >= n || newCol >= m)
                return true;
            if (newRow < 0 || newCol < 0 || heights[newRow][newCol] > heights[r][c])
                continue;
            else
                res |= bottomRightCheck(newRow, newCol, heights, vis);
        }
        return res;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<bool>> vis1(n, vector<bool>(m, false));
                vector<vector<bool>> vis2(n, vector<bool>(m, false));
                bool topLeft = false, bottomRight = false;
                if (topLeftCheck(i, j, heights, vis1))
                {
                    topLeft = true;
                }
                if (bottomRightCheck(i, j, heights, vis2))
                {
                    bottomRight = true;
                }
                if (topLeft && bottomRight)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> ans = s.pacificAtlantic(nums);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

417. Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific
Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where
heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north,
south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow
from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5

*/

/*
************* Java Code **************



*/