#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        // TC: O(n*m)
        // SC: O(1)
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int minCol = 0;
            int minValue = matrix[i][0];
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] < minValue)
                {
                    minValue = matrix[i][j];
                    minCol = j;
                }
            }

            int row = 0;
            int col = minCol;
            int maxValue = matrix[0][minCol];
            while (row < n)
            {
                if (matrix[row][col] > maxValue)
                {
                    maxValue = matrix[row][col];
                }
                row++;
            }
            if (minValue == maxValue)
            {
                ans.push_back(minValue);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<int> ans = s.luckyNumbers(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/lucky-numbers-in-a-matrix

Youtube: https://www.youtube.com/watch?v=iUM2dOAOA9s

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Leetcode%20Easy/Lucky%20Numbers%20in%20a%20Matrix.cpp

algorithm:

- Optimal Approach:

- First we traverse through each row.
- Find the min value and its index.
- Now in that column, we try to find the max value.
- If (minValue == maxValue), then we push it into our ans array.


*/

/*

1380. Lucky Numbers in a Matrix

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and
maximum in its column.

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.

*/

/*
************* Java Code **************

public List<Integer> luckyNumbers (int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            int minCol = 0;
            int minValue = matrix[i][0];
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] < minValue)
                {
                    minValue = matrix[i][j];
                    minCol = j;
                }
            }

            int row = 0;
            int col = minCol;
            int maxValue = matrix[0][minCol];
            while (row < n)
            {
                if (matrix[row][col] > maxValue)
                {
                    maxValue = matrix[row][col];
                }
                row++;
            }
            if (minValue == maxValue)
            {
                ans.add(minValue);
            }
        }
        return ans;
    }

*/