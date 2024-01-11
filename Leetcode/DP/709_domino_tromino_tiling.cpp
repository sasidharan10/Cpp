#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[1001];
    // Recursion + Memoization
    int solve2(int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = ((2 * solve2(n - 1) % mod) + (solve2(n - 3) % mod)) % mod;
    }
    // Tabulation
    int solve(int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((2 * dp[i - 1]) % mod + (dp[i - 3]) % mod) % mod;
        }
        return dp[n];
    }
    int numTilings(int n)
    {
        memset(dp, -1, sizeof(dp));
        // return solve2(n);
        return solve(n);
    }
};
int main()
{
    Solution s;
    int n = 4;
    cout << "Result: " << s.numTilings(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/domino-and-tromino-tiling

Youtube: https://www.youtube.com/watch?v=Iwmn-gFL3c0&t=1923s

algorithm:

*/

/*

790. Domino and Tromino Tiling

You have two types of tiles: a 2 x 1 domino shape and a tromino
shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board.
Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are
different if and only if there are two 4-directionally adjacent cells
on the board such that exactly one of the tilings has both squares occupied by a tile.

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:

Input: n = 1
Output: 1

*/