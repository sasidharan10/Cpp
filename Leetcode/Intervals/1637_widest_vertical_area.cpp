#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = points.size();
        sort(points.begin(), points.end());
        int maxDiff = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x1 = points[i][0];
            int x2 = points[i + 1][0];
            int diff = x2 - x1;
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    cout << "Widest Vertical Area Between Two Points Containing No Points: ";
    cout << s.maxWidthOfVerticalArea(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

Youtube:

algorithm:

- Its given that we need to find max area between 2 points, no other points
  should be betweeen. Its also given that the vertical height is infinity.
- Hence, we just need to find max width between 2 points, and that will be our answer.
- Hence we sort the points, based on x-axis, so, while we traverse, we only
  check 2 adjacent points, and ensuring no other points intersect between them.
- We canculate its width, and update the maxDiff.

*/

/*

1637. Widest Vertical Area Between Two Points Containing No Points

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest
vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the
y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

Example 1:

Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.

Example 2:

Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3

*/