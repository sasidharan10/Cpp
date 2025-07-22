#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canAttendMeetings(vector<vector<int>> &intervals)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = intervals.size();

        vector<int> startTime(n, 0);
        vector<int> endTime(n, 0);
        for (int i = 0; i < n; i++)
        {
            startTime[i] = intervals[i][0];
            endTime[i] = intervals[i][1];
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int cnt = 0;
        int minRooms = 1;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (startTime[i] < endTime[j])
            {
                cnt++;
                i++;
                if (cnt > minRooms)
                    minRooms = cnt;
            }
            else
            {
                j++;
                cnt--;
            }
        }
        return minRooms;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> nums{{0, 30}, {5, 10}, {15, 20}};
    // vector<vector<int>> nums{{7, 10}, {2, 4}};
    vector<vector<int>> nums{{1, 5}, {3, 6}};
    cout << "Result: " << s.canAttendMeetings(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://www.codingninjas.com/studio/problems/meeting-room-ii_893289

Youtube: https://www.youtube.com/watch?v=FdzJmTCVyJU

algorithm:

- Optimal Approach:

- Extract startTime[] and endTime[] from intervals.
- Sort both arrays.
- Use two pointers i (start) and j (end):
- If start[i] < end[j]: overlap → cnt++, move i.
- Else: meeting ended → cnt--, move j.
- Track max cnt as minRooms.

*/

/*

Meeting Rooms II

Given an array of meeting time interval objects consisting of start and end times 
[[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of days required 
to schedule all meetings without any conflicts.

Note: (0,8),(8,10) is not considered a conflict at 8.

Example 1:

Input: intervals = [(0,40),(5,10),(15,20)]
Output: 2

Explanation:
day1: (0,40)
day2: (5,10),(15,20)

Example 2:

Input: intervals = [(4,9)]
Output: 1
Constraints:

0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000

*/

/*   
************* Java Code **************

    public static int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;

        int[] startTime = new int[n];
        int[] endTime = new int[n];
        for (int i = 0; i < n; i++) {
            startTime[i] = intervals[i][0];
            endTime[i] = intervals[i][1];
        }
        Arrays.sort(startTime);
        Arrays.sort(endTime);
        int cnt = 0;
        int minRooms = 1;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (startTime[i] < endTime[j]) {
                cnt++;
                i++;
                if (cnt > minRooms)
                    minRooms = cnt;
            } else {
                j++;
                cnt--;
            }
        }
        return minRooms;
    }

*/