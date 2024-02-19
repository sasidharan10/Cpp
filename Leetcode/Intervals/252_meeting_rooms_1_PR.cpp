#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
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
- https://leetcode.ca/2016-08-08-252-Meeting-Rooms/

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/