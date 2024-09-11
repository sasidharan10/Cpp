#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        // TC: O(max(rows,cols)^2)
        // SC: O(1)
        
        int dir = 0;
        int steps = 0;
        int visitedCells = 1;
        vector<vector<int>> res;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // E S W N
        int sz = rows * cols;
        res.push_back({rStart, cStart});
        while (visitedCells < sz)
        {
            if (dir == 0 || dir == 2)
                steps++;

            for (int i = 0; i < steps; i++)
            {
                rStart += direction[dir][0];
                cStart += direction[dir][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    res.push_back({rStart, cStart});
                    visitedCells++;
                }
            }

            dir = (dir + 1) % 4;
        }
        return res;
    }
};
int main()
{
    Solution s;
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    vector<vector<int>> ans = s.spiralMatrixIII(rows, cols, rStart, cStart);
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

leetcode: https://leetcode.com/problems/spiral-matrix-iii

Youtube: https://www.youtube.com/watch?v=dt0UzAz7SPg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Spiral%20Matrix%20III.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

885. Spiral Matrix III

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner
is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move
outside the grid's boundary, we continue our walk outside the grid (but may return to the
grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

Example 1:

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],
[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols

*/

/*
************* Java Code **************

    public static int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dir = 0;
        int steps = 0;
        int sz = rows * cols;
        int[][] res = new int[sz][2];
        int[][] direction = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int idx = 0;
        res[idx] = new int[] { rStart, cStart };
        idx++;
        while (idx < sz) {
            if (dir == 0 || dir == 2)
                steps++;

            for (int i = 0; i < steps; i++) {
                rStart += direction[dir][0];
                cStart += direction[dir][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res[idx] = new int[] { rStart, cStart };
                    idx++;
                }
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }

*/