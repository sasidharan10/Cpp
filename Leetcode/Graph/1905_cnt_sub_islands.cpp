#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dRow[4]{-1, 0, 1, 0};
    int dCol[4]{0, 1, 0, -1};
    
    // Using BFS
    int checkSubIsland2(int row, int col, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        // TC: O(n*m)
        // SC: O(n*m)  // using queue

        int n = grid1.size();
        int m = grid1[0].size();
        bool result = true;
        queue<pair<int, int>> que;

        grid2[row][col] = -1;
        que.push({row, col});
        while (!que.empty())
        {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            if (grid1[r][c] != 1)
                result = false;
            // Why not return false here itself?
            // because, we need to mark all cells of the island as visited, so we dont need to call
            // bfs for those unvisited cells again.

            for (int i = 0; i < 4; i++)
            {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid2[newRow][newCol] == 1)
                {
                    grid2[newRow][newCol] = -1;
                    que.push({newRow, newCol});
                }
            }
        }
        return result;
    }
    // Using DFS
    bool checkSubIsland(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        // TC: O(n*m)
        // SC: O(n*m)  // Stack space

        int n = grid1.size();
        int m = grid1[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return true;

        if (grid2[i][j] != 1)
            return true;

        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(i + 1, j, grid1, grid2);
        result = result & checkSubIsland(i - 1, j, grid1, grid2);
        result = result & checkSubIsland(i, j + 1, grid1, grid2);
        result = result & checkSubIsland(i, j - 1, grid1, grid2);

        return result;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1 && checkSubIsland2(i, j, grid1, grid2))
                {
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
    vector<vector<int>> grid1{{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2{{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
    cout << "Result: " << s.countSubIslands(grid1, grid2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-sub-islands

Youtube: https://www.youtube.com/watch?v=OeaEOoM-g98

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Count%20Sub%20Islands.cpp

algorithm:

- Brute Force Approach:

- Using either BFS or DFS

- Optimal Approach:

- Using Disjoint set. Incomplete.

*/

/*

1905. Count Sub Islands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water)
and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical).
Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the
cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.

*/

/*
************* Java Code **************

    public static int[] dRow = { -1, 0, 1, 0 };
    public static int[] dCol = { 0, 1, 0, -1 };

    // Using BFS
    public static boolean checkSubIsland2(int row, int col, int[][] grid1, int[][] grid2) {
        int n = grid1.length;
        int m = grid1[0].length;
        boolean result = true;
        Queue<int[]> que = new LinkedList<>();

        grid2[row][col] = -1;
        que.offer(new int[] { row, col });
        while (!que.isEmpty()) {
            int r = que.peek()[0];
            int c = que.peek()[1];
            que.poll();

            if (grid1[r][c] != 1)
                result = false;

            for (int i = 0; i < 4; i++) {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid2[newRow][newCol] == 1) {
                    grid2[newRow][newCol] = -1;
                    que.offer(new int[] { newRow, newCol });
                }
            }
        }
        return result;
    }

    // Using DFS
    public static boolean checkSubIsland(int i, int j, int[][] grid1, int[][] grid2) {
        int n = grid1.length;
        int m = grid1[0].length;

        if (i < 0 || i >= n || j < 0 || j >= m)
            return true;

        if (grid2[i][j] != 1)
            return true;

        grid2[i][j] = -1;

        boolean result = (grid1[i][j] == 1);

        result = result & checkSubIsland(i + 1, j, grid1, grid2);
        result = result & checkSubIsland(i - 1, j, grid1, grid2);
        result = result & checkSubIsland(i, j + 1, grid1, grid2);
        result = result & checkSubIsland(i, j - 1, grid1, grid2);

        return result;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n = grid1.length;
        int m = grid1[0].length;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && checkSubIsland(i, j, grid1, grid2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

*/