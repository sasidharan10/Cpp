#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    int largestSubmatrix3(vector<vector<int>> &matrix)
    {
        // TC: O(n*mlogm)
        // SC: O(n*m)

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = INT_MIN;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (matrix[row][col] == 1 && row > 0)
                    matrix[row][col] += matrix[row - 1][col];
            }
            vector<int> height = matrix[row];
            sort(height.begin(), height.end(), greater<int>());
            for (int i = 0; i < m; i++)
            {
                int base = i + 1;
                maxArea = max(maxArea, height[i] * base);
            }
        }
        return maxArea;
    }
    // Better, but in leetcode, brute is performing better
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        // TC: O(n*mlogm)
        // SC: O(m)

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = INT_MIN;
        vector<int> prevHeight(m, 0);
        for (int row = 0; row < n; row++)
        {
            vector<int> curHeight = matrix[row];
            for (int col = 0; col < m; col++)
            {
                if (curHeight[col] == 1)
                    curHeight[col] += prevHeight[col];
            }
            vector<int> height = curHeight;
            sort(height.begin(), height.end(), greater<int>());
            for (int i = 0; i < m; i++)
            {
                int base = i + 1;
                maxArea = max(maxArea, height[i] * base);
            }
            prevHeight = curHeight;
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix{{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    cout << "Result: " << s.largestSubmatrix(matrix) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-submatrix-with-rearrangements

Youtube: https://www.youtube.com/watch?v=Cs-xXLHG1BY

algorithm:

*/

/*

1727. Largest Submatrix With Rearrangements

You are given a binary matrix matrix of size m x n, and you are allowed to rearrange
the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the
submatrix is 1 after reordering the columns optimally.


Example 1:

Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:

Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is
no way to make a submatrix of 1s larger than an area of 2.

*/