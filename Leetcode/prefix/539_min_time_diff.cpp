#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Storing in array and sorting.
    int findMinDifference2(vector<string> &timePoints)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = timePoints.size();
        vector<int> timeNum;
        for (int i = 0; i < n; i++)
        {
            string hours = timePoints[i].substr(0, 2);
            string minutes = timePoints[i].substr(3, 2);
            int hrs = stoi(hours);
            int mins = stoi(minutes);
            timeNum.push_back(60 * hrs + mins);
        }
        sort(timeNum.begin(), timeNum.end());
        int m = timeNum.size();
        int minDiff = INT_MAX;
        for (int i = 1; i < m; i++)
        {
            int diff = timeNum[i] - timeNum[i - 1];
            minDiff = min(minDiff, diff);
        }
        // calculating counter clockwise value
        int lastdiff = (1440 + timeNum[0]) - timeNum[m - 1];
        minDiff = min(minDiff, lastdiff);
        return minDiff;
    }

    // Optimal - Using counting sort.
    int findMinDifference(vector<string> &timePoints)
    {
        // TC: O(n) + O(1440)
        // SC: O(1440)

        int n = timePoints.size();
        vector<bool> timeNum(1440, false);
        for (int i = 0; i < n; i++)
        {
            string hours = timePoints[i].substr(0, 2);
            string minutes = timePoints[i].substr(3, 2);
            int hrs = stoi(hours);
            int mins = stoi(minutes);
            int time = 60 * hrs + mins;
            if (timeNum[time])
                return 0;
            timeNum[time] = true;
        }
        int firstTimeSeen = -1;
        int lastTimeSeen = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i <= 1440; i++)
        {
            if (timeNum[i])
            {
                if (firstTimeSeen == -1)
                {
                    firstTimeSeen = i;
                    lastTimeSeen = i;
                }
                else
                {
                    int diff = i - lastTimeSeen;
                    minDiff = min(minDiff, diff);
                    lastTimeSeen = i;
                }
            }
        }

        // calculating counter clockwise value between first and last value
        int lastdiff = (1440 + firstTimeSeen) - lastTimeSeen;
        minDiff = min(minDiff, lastdiff);
        return minDiff;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"00:00", "23:59", "00:00"};
    // vector<string> nums{"23:59", "00:00"};
    cout << "Result: " << s.findMinDifference(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-time-difference

Youtube: https://www.youtube.com/watch?v=ftCheG0m85k

Code link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Minimum%20Time%20Difference.cpp

algorithm:

- Better Approach:

- Iterate though the array, and split the string into hrs, and minutes.
- Convert the hrs, mins into seconds. and then store in an array.
- Sort the array.
- Now, to find the minimum difference, iterate though the new array, and check the
  difference between the adjacent time.
- Edge case. Since time is like an circular array, we need to check the difference
  between the time[n-1] - time[0] also.
- Add 1440 to time[0], then subtract time[n-1].

- Optimal Approach:

- Use counting sort, since the range of elements will be [0, 1440].
- Then use the same logic, as explained above.

*/

/*

539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

*/

/*   
************* Java Code **************

    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        boolean[] timeNum = new boolean[1441];
        for (int i = 0; i < n; i++) {
            String hours = timePoints.get(i).substring(0, 2);
            String minutes = timePoints.get(i).substring(3, 5);
            int hrs = Integer.parseInt(hours);
            int mins = Integer.parseInt(minutes);
            int time = 60 * hrs + mins;
            if (timeNum[time])
                return 0;
            timeNum[time] = true;
        }
        int firstTimeSeen = -1;
        int lastTimeSeen = 0;
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i <= 1440; i++) {
            if (timeNum[i]) {
                if (firstTimeSeen == -1) {
                    firstTimeSeen = i;
                    lastTimeSeen = i;
                } else {
                    int diff = i - lastTimeSeen;
                    minDiff = Math.min(minDiff, diff);
                    lastTimeSeen = i;
                }
            }
        }

        int lastdiff = (1440 + firstTimeSeen) - lastTimeSeen;
        minDiff = Math.min(minDiff, lastdiff);
        return minDiff;
    }

*/