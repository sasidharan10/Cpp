#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        string min1 = "61", min2 = "61";
        for (int i = 0; i < n; i++)
        {
            string hours = timePoints[i].substr(1, 2);
            string minutes = timePoints[i].substr(3, 4);
            if (minutes <= min1)
            {
                min2 = min1;
                min1 = minutes;
            }
        }
        int m1 = stoi(min1);
        int m2 = stoi(min2);
        return m2 - m1;
    }
};
int main()
{
    Solution s;
    // vector<string> nums{"00:00", "23:59", "00:00"};
    vector<string> nums{"23:59", "00:00"};
    cout << "Result: " << s.findMinDifference(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

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