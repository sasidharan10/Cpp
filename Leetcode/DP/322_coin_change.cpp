#include <bits/stdc++.h>
using namespace std;
// Recursion
int coinChangeRecur(int ind, int amount, vector<int> &coins)
{
    // TC: >> O(2^n), exponential
    // SC: O(n)

    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
            return amount / coins[ind];
        else
            return 1e9;
    }
    int notTake = coinChangeRecur(ind - 1, amount, coins);
    int take = 1e9;
    if (amount >= coins[ind])
    {
        take = 1 + coinChangeRecur(ind, amount - coins[ind], coins);
    }
    return min(take, notTake);
}
// Memoization
int coinChangeMem(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    // TC: O(n*amount)
    // SC: O(n*amount) + O(n)

    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
            return amount / coins[ind];
        else
            return 1e9;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notTake = coinChangeMem(ind - 1, amount, coins, dp);
    int take = 1e9;
    if (amount >= coins[ind])
    {
        take = 1 + coinChangeMem(ind, amount - coins[ind], coins, dp);
    }
    return dp[ind][amount] = min(take, notTake);
}
// Tabulation
int coinChangeTab(vector<int> &coins, int amount)
{
    // TC: O(n*amount)
    // SC: O(n*amount)

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int target = 0; target <= amount; target++)
    {
        if (target % coins[0] == 0)
            dp[0][target] = target / coins[0];
        else
            dp[0][target] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = dp[ind - 1][target];
            int take = 1e9;
            if (target >= coins[ind])
            {
                take = 1 + dp[ind][target - coins[ind]];
            }
            dp[ind][target] = min(take, notTake);
        }
    }
    return dp[n - 1][amount];
}
// Space Optimization
int coinChangeSpc(vector<int> &coins, int amount)
{
    // TC: O(n*amount)
    // SC: O(amount)

    int n = coins.size();
    vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
    for (int target = 0; target <= amount; target++)
    {
        if (target % coins[0] == 0)
            prev[target] = target / coins[0];
        else
            prev[target] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = prev[target];
            int take = 1e9;
            if (target >= coins[ind])
            {
                take = 1 + cur[target - coins[ind]];
            }
            cur[target] = min(take, notTake);
        }
        prev = cur;
    }
    return prev[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    // int ans =  coinChangeRecur(n - 1, amount, coins);
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // int ans = coinChangeMem(n - 1, amount, coins, dp);
    // int ans =  coinChangeTab(coins, amount);
    int ans = coinChangeSpc(coins, amount);
    if (ans == 1e9)
        return -1;
    else
        return ans;
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Min no of coins to make the amount: " << coinChange(coins, amount);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/coin-change/

Youtube:

algorithm:

*/

/*

322. Coin Change

You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

*/