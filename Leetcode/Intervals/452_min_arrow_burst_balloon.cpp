#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = points.size();
        if (n == 0)
            return 0;
        sort(points.begin(), points.end());
        int prevStart = points[0][0], prevEnd = points[0][1];
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            int curStart = points[i][0];
            int curEnd = points[i][1];

            if (prevEnd < curStart)
            {
                prevStart = curStart;
                prevEnd = curEnd;
                cnt++;
            }
            else
            {
                prevStart = max(prevStart, curStart);
                prevEnd = min(prevEnd, curEnd);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Minimum Number of Arrows to Burst Balloons: ";
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

Youtube: https://www.youtube.com/watch?v=zfcGwzfDNu0

code: 

algorithm:

- here, we are given the width of the balloons, as starting and ending (x ,y) width.
- If 2 balloons overlap, then we need only 1 arrow to burst both balloons, as its given,
  the arrow will penetrate any number of balloons, if overlapped.
- Hence we need to find the no of ballons overlapped with each other, then we can
  return the Min no of arrows to burst all balloons.
- Sort the intervals, by its starting value.
- We know that, to find if 2 balloons are overlapped it should meet this condition:
- Let A = (x1, y1) and B = (x2, y2), then if (y1 > x2) then its overlapping.
- So no need increase the arrow count, we can move to next balloon.
- Now the overlapping interval will change(unless both are same), and the new 
  overlapping interval will be => prev_X = max(x1, x2), prev_Y = min(y1, y2);
- we will compare with prev intervals, and if no overlapping found, we
  increase cnt++, and update the pev intervals, by the current values.

*/

/*

452. Minimum Number of Arrows to Burst Balloons

There are some spherical balloons taped onto a flat wall that represents the XY-plane.
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend]
denotes a balloon whose horizontal diameter stretches between xstart and xend.
You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different
points along the x-axis. A balloon with xstart and xend is burst by an arrow shot
at x if xstart <= x <= xend. There is no limit to the number of arrows that can
be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

*/

/*

public static int findMinArrowShots(int[][] points) {
        int n = points.length;
        if (n == 0)
            return 0;
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int prevStart = points[0][0], prevEnd = points[0][1];
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            int curStart = points[i][0];
            int curEnd = points[i][1];

            if (prevEnd < curStart) {
                prevStart = curStart;
                prevEnd = curEnd;
                cnt++;
            } else {
                prevStart = Math.max(prevStart, curStart);
                prevEnd = Math.min(prevEnd, curEnd);
            }
        }
        return cnt;
    }

*/