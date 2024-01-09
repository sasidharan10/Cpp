#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[1001];
    // Backtraking with memoization
    int solve(int target, int n, vector<int> &nums)
    {
        // TC: O(target)
        // SC: O(target)
        
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= target)
                res += solve(target - nums[i], n, nums);
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        long long res = solve(target, n, nums);
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3};
    int target = 4;
    cout << "Total No of Combinations: " << s.combinationSum4(nums, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/combination-sum-iv/

Youtube:

algorithm:

*/

/*

377. Combination Sum IV

Given an array of distinct integers nums and a target integer target,
return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0

*/