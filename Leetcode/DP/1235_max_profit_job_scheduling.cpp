#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int customUpperBound(int low, int high, int target, vector<vector<int>> &mp)
    {
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mp[mid][0] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    // Recursion
    int jobSchedulingRecur(int ind, int n, vector<vector<int>> &mp)
    {
        if (ind >= n)
            return 0;
        int notTake = 0 + jobSchedulingRecur(ind + 1, n, mp);
        int curStartTime = mp[ind][0];
        int curEndTime = mp[ind][1];
        int currentProfit = mp[ind][2];
        while (ind < n && mp[ind][0] < curEndTime)
        {
            ind++;
        }
        int take = currentProfit + jobSchedulingRecur(ind, n, mp);
        return max(take, notTake);
    }
    // Memoization
    int jobSchedulingMem(int ind, int n, vector<vector<int>> &mp, vector<int> &dp)
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int notTake = 0 + jobSchedulingMem(ind + 1, n, mp, dp);
        int curIndex = ind;
        int curStartTime = mp[ind][0];
        int curEndTime = mp[ind][1];
        int currentProfit = mp[ind][2];
        ind = customUpperBound(ind, n - 1, curEndTime, mp);
        int take = currentProfit + jobSchedulingMem(ind, n, mp, dp);
        return dp[curIndex] = max(take, notTake);
    }
    // Tabulation
    int jobSchedulingTab(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp{startTime[i], endTime[i], profit[i]};
            mp.push_back(temp);
        }
        sort(mp.begin(), mp.end());
        vector<int> dp(n + 1, 0);
        for (int ind = 0; ind < n; ind++)
        {
            
        }
        
    }
    // Space Optimization

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp{startTime[i], endTime[i], profit[i]};
            mp.push_back(temp);
        }
        sort(mp.begin(), mp.end());
        // return jobSchedulingRecur(0, n, mp);
        vector<int> dp(n + 1, -1);
        return jobSchedulingMem(0, n, mp, dp);
    }
};
int main()
{
    Solution s;
    // vector<int> startTime = {1, 2, 3, 4, 6}, endTime = {3, 5, 10, 6, 9}, profit = {20, 20, 100, 70, 60};
    vector<int> startTime = {1, 2, 3, 3}, endTime = {3, 4, 5, 6}, profit = {50, 10, 40, 70};
    cout << "Result: " << s.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-profit-in-job-scheduling

Youtube:

algorithm:

*/

/*

1235. Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i]
to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum
profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start
another job that starts at time X.

Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.

Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

*/