#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int jumpRecur(int ind, int steps, int n, vector<int> &nums)
    {
        if (ind > n - 1)
            return INT_MAX;
        if (ind == n - 1)
            return steps;
        int curSteps = nums[ind];
        if (curSteps == 0)
            return INT_MAX;
        int minSteps = INT_MAX;
        for (int i = 1; i <= curSteps; i++)
        {
            int temp = jumpRecur(ind + i, steps + 1, n, nums);
            minSteps = min(minSteps, temp);
        }
        return minSteps;
    }
    // Memoization
    int jumpMem(int ind, int steps, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind > n - 1)
            return INT_MAX;
        if (ind == n - 1)
            return steps;
        if (dp[ind][steps] != -1)
            return dp[ind][steps];
        int curSteps = nums[ind];
        if (curSteps == 0)
            return INT_MAX;
        int minSteps = INT_MAX;
        if (ind + curSteps >= n - 1)
            return steps + 1;
        for (int i = 1; i <= curSteps; i++)
        {
            int temp = jumpMem(ind + i, steps + 1, n, nums, dp);
            minSteps = min(minSteps, temp);
        }
        return dp[ind][steps] = minSteps;
    }
    // Tabulation
    int jumpGreedy(int ind, int steps, int n, vector<int> &nums)
    {
        if (n == 1)
            return 0;
        int curSteps = nums[ind];
        if (ind + curSteps >= n - 1)
            return steps + 1;
        int maxSteps = nums[ind + 1];
        int maxIndex = ind + 1;
        for (int i = ind + 1; i <= ind + curSteps; i++)
        {
            if (nums[i] >= maxSteps)
            {
                maxSteps = nums[i];
                maxIndex = i;
            }
        }
        return jumpGreedy(maxIndex, steps + 1, n, nums);
    }
    // Space Optimization

    int jump(vector<int> &nums)
    {
        int n = nums.size();
        // return jumpRecur(0, 0, n, nums);
        vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        // return jumpMem(0, 0, n, nums, dp);
        return jumpGreedy(0, 0, n, nums);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 3, 0, 1, 4};
    // vector<int> nums{1, 2, 1, 1, 1};
    vector<int> nums{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    cout << "Result: " << s.jump(nums) << endl;
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






*/