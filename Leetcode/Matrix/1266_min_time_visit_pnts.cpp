#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);

            ans += min(dx, dy) + abs(dx - dy);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> points{{1, 1}, {3, 4}, {-1, 0}};
    cout << "Minimum Time Visiting All Points: " << s.minTimeToVisitAllPoints(points) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-time-visiting-all-points

Youtube: https://www.youtube.com/watch?v=_76B629_qas

algorithm:

*/

/*

1266. Minimum Time Visiting All Points

On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi].
Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then
one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order,
but these do not count as visits.


Example 1:

Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
Time from [1,1] to [3,4] = 3 seconds
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds

Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5



*/