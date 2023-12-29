#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int minDifficultyRecur(int ind, int d, int n, vector<int> &jobDifficulty)
    {
        if (n < d)
            return -1;
        if (d == 1)
            return *max_element(jobDifficulty.begin() + ind, jobDifficulty.end());
        int maxDiff = INT_MIN;
        int res = INT_MAX;
        for (int i = ind; i <= n - d; i++)
        {
            maxDiff = max(jobDifficulty[i], maxDiff);
            res = min(res, maxDiff + minDifficultyRecur(i + 1, d - 1, n, jobDifficulty));
        }
        return res;
    }
    // Memoization
    int minDifficultyMem(int ind, int d, int n, vector<int> &jobDifficulty, vector<vector<int>> &dp)
    {
        if (dp[ind][d] != -1)
            return dp[ind][d];
        if (d == 1)
            return *max_element(jobDifficulty.begin() + ind, jobDifficulty.end());
        int maxDiff = INT_MIN;
        int res = INT_MAX;
        for (int i = ind; i <= n - d; i++)
        {
            maxDiff = max(jobDifficulty[i], maxDiff);
            res = min(res, maxDiff + minDifficultyMem(i + 1, d - 1, n, jobDifficulty, dp));
        }
        return dp[ind][d] = res;
    }
    // Tabulation
    int minDifficultyTab(vector<int> &jobDifficulty, int day)
    {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(day + 1, -1));
        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][1] = *max_element(jobDifficulty.begin() + ind, jobDifficulty.end());
        }

        for (int d = 2; d <= day; d++)
        {
            for (int ind = 0; ind <= n - d; ind++)
            {
                int maxDiff = INT_MIN;
                int res = INT_MAX;
                for (int i = ind; i <= n - d; i++)
                {
                    maxDiff = max(jobDifficulty[i], maxDiff);
                    res = min(res, maxDiff + dp[i + 1][d - 1]);
                }
                dp[ind][d] = res;
            }
        }
        return dp[0][day];
    }
    // Space Optimization (not working)
    int minDifficultySpc(vector<int> &jobDifficulty, int day)
    {
        int n = jobDifficulty.size();
        vector<int> ahead(day + 1, -1), cur(day + 1, -1);
        // ahead[1] = jobDifficulty[0];
        ahead[1] =*max_element(jobDifficulty.begin(), jobDifficulty.end());

        for (int d = 2; d <= day; d++)
        {
            for (int ind = 0; ind <= n - d; ind++)
            {
                int maxDiff = INT_MIN;
                int res = INT_MAX;
                for (int i = ind; i <= n - d; i++)
                {
                    maxDiff = max(jobDifficulty[i], maxDiff);
                    res = min(res, maxDiff + ahead[d - 1]);
                }
                cur[d] = res;
            }
            ahead = cur;
        }
        return cur[day];
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        // return minDifficultyRecur(0, d, n, jobDifficulty);
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        // return minDifficultyMem(0, d, n, jobDifficulty, dp);
        return minDifficultyTab(jobDifficulty, d);
        // return minDifficultySpc(jobDifficulty, d);
    }
};
int main()
{
    Solution s;
    vector<int> nums{6, 5, 4, 3, 2, 1};
    int d = 2;
    cout << "Result: " << s.minDifficulty(nums, d) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

Youtube: https://www.youtube.com/watch?v=smTnSl6UKi0
Youtube: https://www.youtube.com/watch?v=TjyYTng3f5A

algorithm:

- We need to separate the job difficulty array into 'n' parts,
  such that, sum of max of each part should be minimum.
- if (n < d) means less jobs, but more days, hence we cannot divide
  without empty days, hence return -1.
- We ue loop to take ith job into a day, and move to next day.
- Ex: 
- (6), (5, 4, 3, 2, 1) = 6 + 5 = 11
- (6, 5), (4, 3, 2, 1) = 6 + 4 = 10
- (6, 5, 4), (3, 2, 1) = 6 + 3 = 9
- (6, 5, 4, 3), (2, 1) = 6 + 2 = 8
- (6, 5, 4, 3, 2), (1) = 6 + 1 = 7
- ans = 7.

*/

/*

1335. Minimum Difficulty of a Job Schedule

You want to schedule a list of jobs in d days. Jobs are dependent
(i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job
schedule is the sum of difficulties of each day of the d days.
The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d.
The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot
find a schedule for the jobs return -1.

Example 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7

Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day.
you cannot find a schedule for the given jobs.

Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.

*/