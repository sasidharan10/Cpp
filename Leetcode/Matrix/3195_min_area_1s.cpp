#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        // TC: O(n * m) → scan entire grid
        // SC: O(1)     → only variables used

        int n = grid.size();
        int m = grid[0].size();

        // Track boundaries of the rectangle containing all 1’s
        int top = INT_MAX;
        int bottom = INT_MIN;
        int left = INT_MAX;
        int right = INT_MIN;

        // Scan the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    top = min(top, i);       // update top-most row
                    bottom = max(bottom, i); // update bottom-most row
                    left = min(left, j);     // update left-most col
                    right = max(right, j);   // update right-most col
                }
            }
        }

        // Dimensions of bounding rectangle
        int len = right - left + 1;
        int height = bottom - top + 1;

        return len * height;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{0, 1, 0}, {1, 0, 1}};
    cout << "Result: " << s.minimumArea(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i

Youtube: https://www.youtube.com/watch?v=fE0x8ZlyG_w

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Find%20the%20Minimum%20Area%20to%20Cover%20All%20Ones%20I.cpp

algorithm:

- Optimal Approach:

- Goal: find smallest rectangle covering all 1s in the grid.
- Track min/max row and col where 1s appear.
- Rectangle spans from (top, left) to (bottom, right).
- Area = (right - left + 1) * (bottom - top + 1).

*/

/*

3195. Find the Minimum Area to Cover All Ones I

You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest
area, such that all the 1's in grid lie inside this rectangle.
Return the minimum possible area of the rectangle.

Example 1:

Input: grid = [[0,1,0],[1,0,1]]
Output: 6

Explanation:
The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[1,0],[0,0]]
Output: 1

Explanation:
The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.

*/

/*
************* Java Code **************

    public static int minimumArea(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int top = Integer.MAX_VALUE;
        int bottom = Integer.MIN_VALUE;
        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    top = Math.min(top, i);
                    bottom = Math.max(bottom, i);
                    left = Math.min(left, j);
                    right = Math.max(right, j);
                }
            }
        }
        int len = right - left + 1;
        int height = bottom - top + 1;
        return len * height;
    }


*/