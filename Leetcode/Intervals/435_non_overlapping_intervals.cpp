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