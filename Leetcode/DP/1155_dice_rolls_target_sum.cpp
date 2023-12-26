#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int mod = 1e9 + 7;

public:
    // Recursion
    int numRollsToTargetRecur(int n, int k, int target)
    {
        if (n == 0)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        if (target < 0)
            return 0;
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum = (sum + numRollsToTargetRecur(n - 1, k, target - i)) % mod;
        }
        return sum;
    }
    // Memoization
    int numRollsToTargetMem(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        if (target < 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum = (sum + numRollsToTargetMem(n - 1, k, target - i, dp)) % mod;
        }
        return dp[n][target] = sum;
    }
    // Tabulation
    int numRollsToTargetTab(int N, int k, int tgt)
    {
        vector<vector<int>> dp(N + 1, vector<int>(tgt + 1, 0));
        dp[0][0] = 1;
        for (int n = 1; n <= N; n++)
        {
            for (int target = 1; target <= tgt; target++)
            {
                int sum = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (target - i < 0)
                        continue;
                    sum = (sum + dp[n - 1][target - i]) % mod;
                }
                dp[n][target] = sum;
            }
        }
        return dp[N][tgt];
    }
    // Space Optimization
    int numRollsToTargetSpc(int N, int k, int tgt)
    {
        vector<int> prev(tgt + 1, 0);
        vector<int> cur(tgt + 1, 0);
        prev[0] = 1;
        for (int n = 1; n <= N; n++)
        {
            for (int target = 1; target <= tgt; target++)
            {
                int sum = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (target - i < 0)
                        continue;
                    sum = (sum + prev[target - i]) % mod;
                }
                cur[target] = sum;
            }
            prev = cur;
        }
        return cur[tgt];
    }
    int numRollsToTarget(int n, int k, int target)
    {
        // return numRollsToTargetRecur(n, k, target);
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return numRollsToTargetMem(n, k, target, dp);
        // return numRollsToTargetTab(n, k, target);
        return numRollsToTargetSpc(n, k, target);
    }
};
int main()
{
    Solution s;
    // int n = 2, k = 6, target = 7;
    int n = 30, k = 30, target = 500;
    cout << "Number of Dice Rolls With Target Sum: " << s.numRollsToTarget(n, k, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

Youtube: https://www.youtube.com/watch?v=nQw9gVaIjGo

algorithm:

- DP

*/

/*

1155. Number of Dice Rolls With Target Sum

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways
(out of the kn total ways) to roll the dice, so the sum of the face-up
numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.

*/