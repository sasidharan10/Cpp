#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool checkRow(int row, int col, int m, vector<vector<int>> &mat)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[row][j] == 1 && j != col)
                return false;
        }
        return true;
    }
    bool checkCol(int row, int col, int n, vector<vector<int>> &mat)
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] == 1 && i != row)
                return false;
        }
        return true;
    }

public:
    // Brute
    int numSpecial2(vector<vector<int>> &mat)
    {
        // TC: O(n*m) * O(n + m)
        // SC: O(1)

        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (checkRow(i, j, m, mat) && checkCol(i, j, n, mat))
                        cnt++;
                }
            }
        }
        return cnt;
    }
    // optimal
    int numSpecial(vector<vector<int>> &mat)
    {
        // TC: O(n*m)
        // SC: O(n + m)

        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1 && row[i] == 1 && col[i] == 1)
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
    vector<vector<int>> mat{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << "No of Special Positions in Matrix: " << s.numSpecial(mat) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/special-positions-in-a-binary-matrix

Youtube:

algorithm:

- we keep the count of 1's in each row and column.
- then if we encounter mat[i][j]==1, we check if no of 1's in its row and col ==1,
  if yes, then its a special cell.

*/

/*

1582. Special Positions in a Binary Matrix

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements 
in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:

Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and 
all other elements in row 1 and column 2 are 0.

Example 2:

Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

*/