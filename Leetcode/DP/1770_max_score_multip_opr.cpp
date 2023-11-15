#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int m;
    int n;
    // Recursion
    long long maximumScoreRecur(int s, int i, vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        if (i == m)
            return 0;
        int e = n - (i - s) - 1;
        long long beg = nums[s] * multipliers[i] + maximumScoreRecur(s + 1, i + 1, nums, multipliers);
        long long last = nums[e] * multipliers[i] + maximumScoreRecur(s, i + 1, nums, multipliers);
        return max(beg, last);
    }
    // Memoization
    long long maximumScoreMem(int s, int i, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (i == m)
            return 0;
        if (dp[s][i] != -1)
            return dp[s][i];
        int e = n - (i - s) - 1;
        long long beg = nums[s] * multipliers[i] + maximumScoreMem(s + 1, i + 1, nums, multipliers, dp);
        long long last = nums[e] * multipliers[i] + maximumScoreMem(s, i + 1, nums, multipliers, dp);
        return dp[s][i] = max(beg, last);
    }
    // Tabulation
    int maximumScoreTab(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int s = n - 1; s >= 0; s--)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                int e = n - (i - s) - 1;
                long long beg = nums[s] * multipliers[i] + dp[s + 1][i + 1];
                long long last = nums[e] * multipliers[i] + dp[s][i + 1];
                dp[s][i] = max(beg, last);
            }
        }
        return dp[0][0];
    }
    // Space Optimization
    int maximumScoreSpc(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<int> ahead(m + 1, 0), cur(m + 1, 0);
        for (int s = n - 1; s >= 0; s--)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                int e = n - (i - s) - 1;
                int beg = nums[s] * multipliers[i] + ahead[i + 1];
                int last = nums[e] * multipliers[i] + cur[i + 1];
                cur[i] = max(beg, last);
            }
            ahead = cur;
        }
        return ahead[0];
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        n = nums.size();
        m = multipliers.size();
        // return maximumScoreRecur(0, 0, nums, multipliers);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return maximumScoreMem(0, 0, nums, multipliers, dp);
        // return maximumScoreTab(nums, multipliers);
        return maximumScoreSpc(nums, multipliers);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-5, -3, -3, -2, 7, 1}, multipliers = {-10, -5, 3, 4, 6};
    cout << "Maximum Score from Performing Multiplication Operations: ";
    cout << s.maximumScore(nums, multipliers) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

Youtube:

algorithm:

*/