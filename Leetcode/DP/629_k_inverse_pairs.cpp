#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int mod = 1e9 + 7;

public:
    // Recursion
    int solveRecur(int n, int k)
    {
        // TC: O(k ^ n)
        // SC: O(n)

        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        int res = 0;
        for (int inv = 0; inv <= min(k, n - 1); inv++)
        {
            res = (res + solveRecur(n - 1, k - inv)) % mod;
        }
        return res;
    }
    // Memoization
    int solveMem(int n, int k, vector<vector<int>> &dp)
    {
        // TC: O(n * k * n)
        // SC: O(n * k) + O(n)

        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        int res = 0;
        for (int inv = 0; inv <= min(k, n - 1); inv++)
        {
            res = (res + solveMem(n - 1, k - inv, dp)) % mod;
        }
        return dp[n][k] = res;
    }
    // Tabulation
    int solveTab(int n, int k)
    {
        // TC: O(n * k * n)
        // SC: O(n * k)

        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                dp[0][j] = 0;
                dp[i][0] = 1;
            }
        }
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int res = 0;
                for (int inv = 0; inv <= min(j, i - 1); inv++)
                {
                    res = (res + dp[i - 1][j - inv]) % mod;
                }
                dp[i][j] = res;
            }
        }
        return dp[n][k];
    }
    // Space Optimization
    int solveSpc(int n, int k)
    {
        // TC: O(n * k * n)
        // SC: O(k)

        if (n == 0)
            return 0;
        if (k == 0)
            return 1;

        vector<int> prev(k + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<int> cur(k + 1, 0);
            cur[0] = 1;
            for (int j = 1; j <= k; j++)
            {
                int res = 0;
                for (int inv = 0; inv <= min(j, i - 1); inv++)
                {
                    res = (res + prev[j - inv]) % mod;
                }
                cur[j] = res;
            }
            prev = cur;
        }
        return prev[k];
    }
    int kInversePairs(int n, int k)
    {
        // return solveRecur(n, k);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        // return solveMem(n, k, dp);
        // return solveTab(n, k);
        return solveSpc(n, k);
    }
};
int main()
{
    Solution s;
    int n = 3, k = 1;
    cout << "Result: " << s.kInversePairs(n, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/k-inverse-pairs-array

Youtube: https://www.youtube.com/watch?v=y9yo1kyW7Bg

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

629. K Inverse Pairs Array

For an integer array nums, an inverse pair is a pair of integers [i, j]
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist
of numbers from 1 to n such that there are exactly k inverse pairs. Since
the answer can be huge, return it modulo 109 + 7.

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers
from 1 to 3 has exactly 0 inverse pairs.

Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

*/