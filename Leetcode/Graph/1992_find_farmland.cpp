#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRow, maxCol;
    int n, m;

    // Using BFS
    void bfs(int r, int c, vector<vector<int>> &land)
    {
        // TC: O(n*m)
        // SC: O(n*m)

        land[r][c] = -1;
        queue<pair<int, int>> que;
        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};
        que.push({r, c});
        while (!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && land[newRow][newCol] == 1)
                {
                    land[newRow][newCol] = -1;
                    que.push({newRow, newCol});
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<int>> &land)
    {
        // TC: O(n*m)
        // SC: O(n*m) stack space
        
        if (r < 0 || r >= n || c < 0 || c >= m || land[r][c] != 1)
            return;
        maxRow = max(maxRow, r);
        maxCol = max(maxCol, c);
        land[r][c] = -1;
        dfs(r - 1, c, land);
        dfs(r, c + 1, land);
        dfs(r + 1, c, land);
        dfs(r, c - 1, land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 1)
                {
                    maxRow = i;
                    maxCol = j;
                    bfs(i, j, land);
                    // dfs(i, j, land);
                    ans.push_back({i, j, maxRow, maxCol});
                }
            }
        }
        return ans;
    }

    // brute force - finding the rectangle and marking it visited
    vector<vector<int>> findFarmland2(vector<vector<int>> &land)
    {
        // TC: O(n*m)
        // SC: O(1)

        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 1)
                {
                    int r2 = i;
                    int c2 = j;
                    while (r2 < n && land[r2][j] == 1)
                    {
                        r2++;
                    }
                    while (c2 < m && land[i][c2] == 1)
                    {
                        c2++;
                    }
                    r2 = (r2 == 0) ? 0 : r2 - 1;
                    c2 = (c2 == 0) ? 0 : c2 - 1;
                    ans.push_back({i, j, r2, c2});
                    for (int k = i; k <= r2; k++)
                    {
                        for (int l = j; l <= c2; l++)
                        {
                            land[k][l] = -1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    vector<vector<int>> ans = s.findFarmland(nums);
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

leetcode: https://leetcode.com/problems/find-all-groups-of-farmland/

Youtube: https://www.youtube.com/watch?v=3ZaQTCH83fY
 
Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Find%20All%20Groups%20of%20Farmland.cpp

algorithm:

- Similar to no of island problem (LC 200).
- Just do a simple bfs or dfs, until all the adjacent cells are visited on that particular land is visited.
- Its given, all farmlands will be a rectangle.
- Since we search for a land from top left, the first cell we encounter in that grid will be the 
  top-left cell of the land.
- To findthe bottom-right cell, we just have to take max(i, j) from that cell, since its a rectangle
- We do this until all cells are visited.
- In this way, each time we visit a cell, that land will be visited and we push its coordinated in ans.

*/

/*

1992. Find All Groups of Farmland

You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of
forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that
consist entirely of farmland. These rectangular areas are called groups. No two groups
are adjacent, meaning farmland in one group is not four-directionally adjacent to
another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0)
and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left
and bottom right corner of each group of farmland. A group of farmland with a top left
corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length
array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of
farmland in land. If there are no groups of farmland, return an empty array. You may
return the answer in any order.

*/

/*
************* Java Code **************

public static int[][] findFarmland(int[][] land) {
        int n = land.length;
        int m = land[0].length;
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int r2 = i;
                    int c2 = j;
                    while (r2 < n && land[r2][j] == 1) {
                        r2++;
                    }
                    while (c2 < m && land[i][c2] == 1) {
                        c2++;
                    }
                    r2 = (r2 == 0) ? 0 : r2 - 1;
                    c2 = (c2 == 0) ? 0 : c2 - 1;
                    res.add(new int[] { i, j, r2, c2 });

                    for (int k = i; k <= r2; k++) {
                        for (int l = j; l <= c2; l++) {
                            land[k][l] = -1;
                        }
                    }
                }
            }
        }
        int[][] ans = new int[res.size()][4];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }

*/