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

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/