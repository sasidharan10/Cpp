#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        // TC: O(n+m)
        // SC: O(n*m)
        
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            res[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];

            if (rowSum[i] == 0)
                i++;
            else
                j++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> rowSum = {5, 7, 10}, colSum = {8, 6, 8};
    vector<vector<int>> ans = s.restoreMatrix(rowSum, colSum);
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

leetcode: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

Youtube: https://www.youtube.com/watch?v=9dKdLNlmxco

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Find%20Valid%20Matrix%20Given%20Row%20and%20Column%20Sums.cpp

algorithm:

- Optimal Approach:

- We create a m*n matrix with all values assigned as 0.
- We use 2 pointers, pointing at both arrays.
- Find the min element from the two, and assign it into the matrix.
- Subtract that value from both the arrays, since that value is added into the matrix.
- Now the array, wher the value became 0, we move the pointer to next element.
- We do this until the pointer goes out of bound. By that time, all elemetns would have been
  aadded into the matrix.

*/

/*

1605. Find Valid Matrix Given Row and Column Sums

You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the
sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column
of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know
the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the
rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at
least one matrix that fulfills the requirements exists.

Example 1:

Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation:
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]

Example 2:

Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]

Constraints:

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 10^8
sum(rowSum) == sum(colSum)

*/

/*
************* Java Code **************

public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n = rowSum.length;
        int m = colSum.length;
        int[][] res = new int[n][m];

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            res[i][j] = Math.min(rowSum[i], colSum[j]);

            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];

            if (rowSum[i] == 0)
                i++;
            else
                j++;
        }
        return res;
    }

*/