#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
    }
};
int main()
{
    Solution s;
    vector<int> nums{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = s.dailyTemperatures(nums);
    cout << "No of days, to find warmer temperature: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/daily-temperatures

Youtube: https://www.youtube.com/watch?v=ZhZEmGv-sOY

algorithm:

*/

/*

739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return
an array answer such that answer[i] is the number of days you have to wait
after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/
