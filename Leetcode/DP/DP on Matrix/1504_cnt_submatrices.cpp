#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Helper: counts number of subarrays filled with 1’s
    int countSubArrays(vector<int> &nums)
    {
        int n = nums.size();
        int len = 0; // length of current streak of 1’s
        int res = 0; // total subarrays of 1’s

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                len++; // extend streak
            else
                len = 0; // reset if zero found

            res += len; // add subarrays ending here
        }
        return res;
    }

    // Main function: count submatrices filled with 1’s
    int numSubmat(vector<vector<int>> &mat)
    {
        // TC: O(n * n * m)  -> choose row-pair (n^2), scan columns (m)
        // SC: O(m)          -> temporary array

        int n = mat.size();
        int m = mat[0].size();

        int res = 0;
        // Fix a starting row
        for (int startRow = 0; startRow < n; startRow++)
        {
            vector<int> temp(m, 1); // temporary column array (all 1’s initially)

            // Extend endRow downward
            for (int endRow = startRow; endRow < n; endRow++)
            {
                // Update temp: keep only columns that are 1’s in all rows [startRow..endRow]
                for (int col = 0; col < m; col++)
                {
                    temp[col] = temp[col] & mat[endRow][col];
                }

                // Count subarrays of 1’s in temp → gives number of submatrices
                res += countSubArrays(temp); // O(m)
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << "Result: " << s.numSubmat(mat) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-submatrices-with-all-ones

Youtube: https://www.youtube.com/watch?v=dYsJpsgCPzw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Count%20Submatrices%20With%20All%20Ones.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- Fix top row (startRow).
- For each bottom row (endRow), build temp[col] = 1 if all cells in column col are 1 in rows [startRow..endRow].
- Now the problem reduces to counting subarrays of consecutive 1’s in temp.
- Each such subarray corresponds to a valid submatrix of 1’s.
- Use helper countSubArrays() to count them in O(m).
- Repeat for all row pairs.

*/

/*

1504. Count Submatrices With All Ones

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

Example 1:

Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:

Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.

Constraints:

1 <= m, n <= 150
mat[i][j] is either 0 or 1.

*/

/*
************* Java Code **************

    public static int countSubArrays(int[] nums) {
        int n = nums.length;
        int len = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                len++;
            else
                len = 0;
            res += len;
        }
        return res;
    }

    public static int numSubmat(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int res = 0;
        for (int startRow = 0; startRow < n; startRow++) {
            int[] temp = new int[m];
            Arrays.fill(temp, 1);
            for (int endRow = startRow; endRow < n; endRow++) {
                for (int col = 0; col < m; col++) {
                    temp[col] = temp[col] & mat[endRow][col];
                }
                res += countSubArrays(temp); // O(m)
            }
        }
        return res;
    }

*/