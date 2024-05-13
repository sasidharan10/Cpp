#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        // TC: O(n*n)
        // SC: O(n*n)
        
        int n = grid.size();
        int m = grid[0].size();
        int maxi;
        vector<vector<int>> ans(n - 2, vector<int>(m - 2, 0));
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                maxi = 0;
                for (int row = i; row < i + 3; row++)
                {
                    for (int col = j; col < j + 3; col++)
                    {
                        maxi = max(maxi, grid[row][col]);
                    }
                }
                ans[i][j] = maxi;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    vector<vector<int>> ans = s.largestLocal(nums);
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

leetcode: https://leetcode.com/problems/largest-local-values-in-a-matrix/

Youtube: https://www.youtube.com/watch?v=dulcB6sdIFU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Leetcode%20Easy/Largest%20Local%20Values%20in%20a%20Matrix.cpp

algorithm:

- Optimal Approach:

-

*/

/*

2373. Largest Local Values in a Matrix

You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered
around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.

Example 1:

Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a
contiguous 3 x 3 matrix in grid.

Example 2:

Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

*/

/*
************* Java Code **************

public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int maxi;
        int[][] ans = new int[n - 2][m - 2];
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                maxi = 0;
                for (int row = i; row < i + 3; row++)
                {
                    for (int col = j; col < j + 3; col++)
                    {
                        maxi = Math.max(maxi, grid[row][col]);
                    }
                }
                ans[i][j] = maxi;
            }
        }
        return ans;
    }

*/