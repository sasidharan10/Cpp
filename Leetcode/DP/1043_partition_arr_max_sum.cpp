#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solveRecur(int ind, int k, int n, vector<int> &arr)
    {
        // TC: O(k ^ n)
        // SC: O(n)

        if (ind >= n)
            return 0;
        int maxi = 0;
        int res = 0;
        for (int i = ind; i < min(n, ind + k); i++)
        {
            maxi = max(maxi, arr[i]);
            int cnt = i - ind + 1;
            res = max(res, cnt * maxi + solveRecur(i + 1, k, n, arr));
        }
        return res;
    }
    // Memoization
    int solveMem(int ind, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        // TC: O(n * k)
        // SC: O(n) + O(n) - ASS

        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int maxi = 0;
        int res = 0;
        for (int i = ind; i < min(n, ind + k); i++)
        {
            maxi = max(maxi, arr[i]);
            int cnt = i - ind + 1;
            res = max(res, cnt * maxi + solveMem(i + 1, k, n, arr, dp));
        }
        return dp[ind] = res;
    }
    // Tabulation
    int solveTab(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int maxi = 0;
            int res = 0;
            for (int i = ind; i < min(n, ind + k); i++)
            {
                maxi = max(maxi, arr[i]);
                int cnt = i - ind + 1;
                res = max(res, cnt * maxi + dp[i + 1]);
            }
            dp[ind] = res;
        }
        return dp[0];
    }
    int solveTab2(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int ind = 1; ind <= n; ind++)
        {
            int maxi = 0;
            int res = 0;
            for (int i = 1; i <= k && ind - i >= 0; i++)
            {
                maxi = max(maxi, arr[ind - i]);
                res = max(res, i * maxi + dp[ind - i]);
            }
            dp[ind] = res;
        }
        return dp[n];
    }
    // Space Optimization
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        // return solveRecur(0, k, n, arr);
        vector<int> dp(n + 1, -1);
        // return solveMem(0, k, n, arr, dp);
        return solveTab(arr, k);
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k = 4;
    cout << "Result: " << s.maxSumAfterPartitioning(nums, k) << endl;
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

1043. Partition Array for Maximum Sum

Given an integer array arr, partition the array into (contiguous) subarrays
of length at most k. After partitioning, each subarray has their values
changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases
are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:

Input: arr = [1], k = 1
Output: 1

*/