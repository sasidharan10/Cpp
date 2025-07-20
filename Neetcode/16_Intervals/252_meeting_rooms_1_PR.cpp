#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    bool canAttendMeetings(vector<vector<int>> intervals)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> A = intervals[i];
            for (int j = i + 1; j < n; j++)
            {
                vector<int> B = intervals[j];
                int start1 = A[0];
                int start2 = B[0];
                int end1 = A[1];
                int end2 = B[1];
                // if (min(end1, end2) > max(start1, start2))
                if ((end1 > start2) && (start1 < end2))
                {
                    return false;
                }
            }
        }
        return true;
    }
    // Optimal
    bool canAttendMeetings2(vector<vector<int>> &intervals)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n - 1; i++)
        {
            int end1 = intervals[i][1];
            int start2 = intervals[i + 1][0];

            if (end1 > start2)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{0, 30}, {5, 10}, {15, 20}};
    vector<vector<int>> nums{{7, 10}, {2, 4}};
    cout << "Result: " << s.canAttendMeetings(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://aaronice.gitbook.io/lintcode/sweep-line/meeting-rooms
-         https://leetcode.ca/2016-08-08-252-Meeting-Rooms/
          https://neetcode.io/problems/meeting-schedule?list=neetcode250

Youtube:

algorithm:

- Brute Force Approach:

- Compare every pair of intervals.
- For each pair, check if they overlap:
- Overlap if: interval1.start < interval2.end && interval2.start < interval1.end
- If any overlap found → return false.
- If no overlaps → return true.
- Time: O(n²), Space: O(1)

- Optimal Approach:

- Sort intervals by start time.
- Traverse intervals from index 1 to n-1.
- For each interval, check if current start < previous end:
- If yes → overlap → return false.
- If no overlaps found → return true.
- Time: O(n log n), Space: O(1)

*/

/*

Meeting Rooms

Given an array of meeting time interval objects consisting of start and end times 
[[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings 
to their schedule without any conflicts.

Example 1:

Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
Explanation:

(0,30) and (5,10) will conflict
(0,30) and (15,20) will conflict

Example 2:

Input: intervals = [(5,8),(9,15)]
Output: true
Note:

(0,8),(8,10) is not considered a conflict at 8

Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000

*/

/*   
************* Java Code **************

    public boolean canAttendMeetings(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < n - 1; i++) {
            int end1 = intervals[i][1];
            int start2 = intervals[i + 1][0];

            if (end1 > start2)
                return false;
        }
        return true;
    }

*/