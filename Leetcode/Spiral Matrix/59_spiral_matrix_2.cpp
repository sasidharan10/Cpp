#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // TC: O(n*m)
        // SC: O(n*m)

        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int left = 0;
        int direction = 0;
        int num = 1;
        while (top <= bottom && left <= right)
        {
            if (direction == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    matrix[top][i] = num;
                    num++;
                }
                top++;
            }
            else if (direction == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    matrix[i][right] = num;
                    num++;
                }
                right--;
            }
            else if (direction == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            else if (direction == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return matrix;
    }
};
int main()
{
    Solution s;
    int n = 4;
    vector<vector<int>> ans = s.generateMatrix(n);
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

leetcode: https://leetcode.com/problems/spiral-matrix-ii

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Simulation

*/

/*

59. Spiral Matrix II

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 20

*/

/*
************* Java Code **************

    public static int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int left = 0;
        int direction = 0;
        int num = 1;
        while (top <= bottom && left <= right) {
            if (direction == 0) {
                for (int i = left; i <= right; i++) {
                    matrix[top][i] = num;
                    num++;
                }
                top++;
            } else if (direction == 1) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right] = num;
                    num++;
                }
                right--;
            } else if (direction == 2) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            } else if (direction == 3) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return matrix;
    }

*/