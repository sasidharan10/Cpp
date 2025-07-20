#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // TC: O(n)
        // SC: O(1)

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int prev_end = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];

            // prev_end is greater, hence these 2 intervals are overlapping
            if (prev_end > cur_start)
            {
                cnt++;
                // Here, we remove the interval, having greater end value, so that we can
                // eliminate the possiblilty of further overlapping intervals.
                if (prev_end > cur_end)
                    prev_end = cur_end;
            }
            else
            {
                prev_end = cur_end;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Minimum number of intervals to be removed to make intervals non-overlapping: ";
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/non-overlapping-intervals

Youtube: https://www.youtube.com/watch?v=nONCGxWoUfM

algorithm: greedy

- Sort the intervals, based on starting values.
- Check if prev_end > cur_start, then the intervals are overlapping, hence increase the count.
- So we have to remove interval, out of these 2, and we remove the interval, having greater
  end value, so that we can eliminate the possiblilty of further overlapping intervals.
- if no overlapping found, we update the prev_end, to compare it with the next interval.

*/

/*

435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of 
intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping. 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 
Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4


*/

/*   
************* Java Code **************

    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int cnt = 0;
        int prev_end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];

            // prev_end is greater, hence these 2 intervals are overlapping
            if (prev_end > cur_start) {
                cnt++;
                // Here, we remove the interval, having greater end value, so that we can
                // eliminate the possiblilty of further overlapping intervals.
                if (prev_end > cur_end)
                    prev_end = cur_end;
            } else {
                prev_end = cur_end;
            }
        }
        return cnt;
    }

*/