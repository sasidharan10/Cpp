#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int matrixScore2(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(1)

        int n = grid.size();
        int m = grid[0].size();

        // Flipping the row, if MSB is 0
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Flipping the columns, having more 0's
        for (int col = 1; col < m; col++)
        {
            int ones = 0;
            for (int row = 0; row < n; row++)
            {
                if (grid[row][col] == 1)
                    ones++;
            }
            int zeroes = n - ones;
            if (ones < zeroes)
            {
                for (int row = 0; row < n; row++)
                {
                    grid[row][col] = 1 - grid[row][col];
                }
            }
        }

        // Calculating and summing the value
        int num = 0;
        int pw;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    pw = m - j - 1;
                    num = num + pow(2, pw);
                }
            }
        }
        return num;
    }
    // Without modifying the matrix
    int matrixScore(vector<vector<int>> &grid)
    {
        // TC: O(n*m)
        // SC: O(1)

        int n = grid.size();
        int m = grid[0].size();

        int num = 0;
        // adding all grid[row][0], since MSB should be 1.
        num = num + n * pow(2, m - 1);
        for (int col = 1; col < m; col++)
        {
            int ones = 0;
            for (int row = 0; row < n; row++)
            {
                // grid[row][0] == 0, then that row is flipped, which means grid[row][col] == 0 is 1.
                if ((grid[row][0] == 1 && grid[row][col] == 1) || (grid[row][0] == 0 && grid[row][col] == 0))
                    ones++;
            }
            int zeroes = n - ones;
            if (ones > zeroes)
            {
                num = num + ones * pow(2, m - col - 1);
            }
            else
                num = num + zeroes * pow(2, m - col - 1);
        }
        return num;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    // vector<vector<int>> nums{{0, 1}, {0, 1}, {0, 1}, {0, 0}};
    cout << "Result: " << s.matrixScore(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/score-after-flipping-matrix/

Youtube: https://www.youtube.com/watch?v=nNRqRWvV23k

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Score%20After%20Flipping%20Matrix.cpp

algorithm:

- Brute Force Approach:

- Fist column contains Most significant bit(MSB). Hence we need to make it 1
  to make the score max.
- Hence, if first value in a row is 0, then we flip the whole row.
- Now we traverse each column, and count no of ones. If there are less ones, 
  then we flip the whole columnm, or we move to next column.
- Finally we calculate the score.

- Optimal Approach: (without modifying the matrix)

- We know, the MSb should be kept as 1, hence we just add those value
  to the score.
- Now based to the first value in each row, we check if that row is flipped or not.
- If flipped, then we treat 0 as 1 in that row, or vice versa.

*/

/*

861. Score After Flipping Matrix

You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row
or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the
matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

Example 1:

Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Example 2:

Input: grid = [[0]]
Output: 1

*/

/*
************* Java Code **************

public int matrixScore(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int num = 0;
        num += n * Math.pow(2, m - 1);
        for (int col = 1; col < m; col++)
        {
            int ones = 0;
            for (int row = 0; row < n; row++)
            {
                if ((grid[row][0] == 1 && grid[row][col] == 1) || (grid[row][0] == 0 && grid[row][col] == 0))
                    ones++;
            }
            int zeroes = n - ones;
            if (ones > zeroes)
                num += ones * Math.pow(2, m - col - 1);
            else
                num += zeroes * Math.pow(2, m - col - 1);
        }
        return num;
    }

*/