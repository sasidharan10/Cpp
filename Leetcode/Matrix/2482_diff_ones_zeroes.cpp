#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getRowOnes(int row, int col, int m, vector<vector<int>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[row][i] == 1)
                cnt++;
        }
        return cnt;
    }
    int getColOnes(int row, int col, int n, vector<vector<int>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][col] == 1)
                cnt++;
        }
        return cnt;
    }
    // Brute
    vector<vector<int>> onesMinusZeros2(vector<vector<int>> &grid)
    {
        // TC: O(n*m) * O(n + m)
        // SC: O(n*m)

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int onesRow = getRowOnes(i, j, m, grid);
                int onesCol = getColOnes(i, j, n, grid);
                int zeroesRow = n - onesRow;
                int zeroesCol = m - onesCol;
                diff[i][j] = onesRow + onesCol - zeroesRow - zeroesCol;
            }
        }
        return diff;
    }

    // Optimal
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(n*m) + O(n + m)
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<int> onesRowArr(n, 0), onesColArr(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    onesRowArr[i]++;
                    onesColArr[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int onesRow = onesRowArr[i];
                int onesCol = onesColArr[j];
                int zeroesRow = n - onesRow;
                int zeroesCol = m - onesCol;
                diff[i][j] = onesRow + onesCol - zeroesRow - zeroesCol;
            }
        }
        return diff;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> ans = s.onesMinusZeros(grid);
    cout << "Difference Between Ones and Zeros in Row and Column: " << endl;
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

leetcode: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

Youtube:

algorithm:

*/

/*

2482. Difference Between Ones and Zeros in Row and Column

You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
Return the difference matrix diff.

Example 1:

Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2

Example 2:

Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5

*/
