#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - TLE
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        // TC: O((n ^ 3) * (m ^ 3))
        // SC: O(1)

        int n = matrix.size();
        int m = matrix[0].size();

        int cnt = 0;

        // Trying All possible start points (x, y)
        for (int start_row = 0; start_row < n; start_row++)
        {
            for (int start_col = 0; start_col < m; start_col++)
            {

                // Trying All possible ending points (x', y')
                for (int end_row = start_row; end_row < n; end_row++)
                {
                    for (int end_col = start_col; end_col < m; end_col++)
                    {

                        // Now iterating the start points and end points
                        int sum = 0;
                        for (int i = start_row; i <= end_row; i++)
                        {
                            for (int j = start_col; j <= end_col; j++)
                            {
                                sum += matrix[i][j];
                            }
                        }

                        if (sum == target)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }

    // Better
    int numSubmatrixSumTarget2(vector<vector<int>> &matrix, int target)
    {
        // TC: O((n ^ 2) * (m ^ 2))
        // SC: O(n * m)

        int n = matrix.size();
        int m = matrix[0].size();
        // Computing sub - matrix sum
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int top = i > 0 ? matrix[i - 1][j] : 0;
                int left = j > 0 ? matrix[i][j - 1] : 0;
                int topLeft = min(i, j) > 0 ? matrix[i - 1][j - 1] : 0;

                matrix[i][j] = matrix[i][j] + top + left - topLeft;
            }
        }

        // finding subMatrix sum:
        int cnt = 0;
        for (int r1 = 0; r1 < n; r1++)
        {
            for (int r2 = r1; r2 < n; r2++)
            {
                for (int c1 = 0; c1 < m; c1++)
                {
                    for (int c2 = c1; c2 < m; c2++)
                    {
                        int top = r1 > 0 ? matrix[r1 - 1][c2] : 0;
                        int left = c1 > 0 ? matrix[r2][c1 - 1] : 0;
                        int topLeft = min(r1, c1) > 0 ? matrix[r1 - 1][c1 - 1] : 0;

                        int curSum = matrix[r2][c2] - top - left + topLeft;
                        if (curSum == target)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    // Optimal
    int numSubmatrixSumTarget3(vector<vector<int>> &matrix, int target)
    {
        // TC: O(m ^ 2 * n)
        // SC: O(n)

        int n = matrix.size();
        int m = matrix[0].size();

        // assigning cumulative rows sum at every i,j
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // finding submatrices with sum k
        int cnt = 0;
        for (int startCol = 0; startCol < m; startCol++)
        {
            for (int j = startCol; j < m; j++)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for (int i = 0; i < n; i++)
                {
                    sum += matrix[i][j] - (startCol > 0 ? matrix[i][startCol - 1] : 0);
                    if (mp[sum - target])
                    {
                        cnt += mp[sum - target];
                    }
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int target = 3;
    cout << "Result: " << s.numSubmatrixSumTarget(matrix, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

Youtube:
Brute: https://www.youtube.com/watch?v=43DRBP2DUHg&t=1s
Optimal: https://www.youtube.com/watch?v=-SWrz90jCUM

algorithm:

- Brute Force Approach:

- finding all possible submatrices takes 4 loops, (2 for starting x,y 
  and 2 for ending x,y)
- 2 more loops to iterate through those sub matrices for getting the sum.

- Better:

- Using prefix sum, we first compute the submatrices sum, and then we check
  it with the target.
- Using only 4 loops, eliminates those 2 extra loops for finding the sum.

- Optimal Approach:

- Using the comcept of "LC 560: No. of subarrays with sum k", we compute 
  the sub matrices sum.
- Refer video and dry run for better understanding.

*/

/*

1074. Number of Submatrices That Sum to Target

Given a matrix and a target, return the number of non-empty
submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y]
with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different
if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices,
plus the 2x2 submatrix.

Example 3:

Input: matrix = [[904]], target = 0
Output: 0

*/