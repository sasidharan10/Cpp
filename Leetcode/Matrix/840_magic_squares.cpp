#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMagicSquare(vector<vector<int>> &grid, int row, int col)
    {
        vector<int> mp(10, 0);
        // check unique values from 1 - 9
        for (int i = row; i < row + 3; i++)
        {
            for (int j = col; j < col + 3; j++)
            {
                if (grid[i][j] < 1 || grid[i][j] > 9 || mp[grid[i][j]] != 0)
                    return false;
                mp[grid[i][j]] = 1;
            }
        }
        // checking all possible row sums and col sums are equal.
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; i++)
        {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum ||
                grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum)
                return false;
        }
        // checking diagonal sums equal.
        int leftDg = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int rightDg = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if (leftDg != sum || rightDg != sum)
            return false;

        return true;
    }
    // Brute force - finding all possible 3*3 squares and check if its a magic square.
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(10)

        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                if (isMagicSquare(grid, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    // vector<vector<int>> grid{{4, 7, 8}, {9, 5, 1}, {2, 3, 6}};
    cout << "Result: " << s.numMagicSquaresInside(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/magic-squares-in-grid

Youtube: https://www.youtube.com/watch?v=KgiW_AtaBPo

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Magic%20Squares%20In%20Grid.cpp

algorithm:

- Brute Force Approach:

- Finding all possible 3*3 squares and check if its a magic square.

- Optimal Approach:

- Not done

*/

/*

840. Magic Squares In Grid

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each
row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15

*/

/*
************* Java Code **************

    public static boolean isMagicSquare(int[][] grid, int row, int col) {
        int[] mp = new int[10];
        // check unique values from 1 - 9
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || mp[grid[i][j]] != 0)
                    return false;
                mp[grid[i][j]] = 1;
            }
        }
        // checking all possible row sums and col sums are equal.
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; i++) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum ||
                    grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum)
                return false;
        }
        // checking diagonal sums equal.
        int leftDg = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int rightDg = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if (leftDg != sum || rightDg != sum)
            return false;

        return true;
    }

    public static int numMagicSquaresInside(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        if (n < 3 || m < 3)
            return 0;
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isMagicSquare(grid, i, j) == true)
                    cnt++;
            }
        }
        return cnt;
    }

*/