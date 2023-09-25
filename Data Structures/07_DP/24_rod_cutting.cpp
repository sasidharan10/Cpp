#include <bits/stdc++.h>
using namespace std;
// Recursion
int cutRodRecur(int ind, int n, vector<int> &price)
{
    // TC: >> O(2^n), exponentially
    // SC: O(n)

    if (ind == 0)
    {
        return n * price[0];
    }
    int notTake = cutRodRecur(ind - 1, n, price);
    int take = -1e9;
    int rodlength = ind + 1;
    if (n >= rodlength)
    {
        take = price[ind] + cutRodRecur(ind, n - rodlength, price);
    }
    return max(take, notTake);
}
// Memoization
int cutRodMem(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    // TC: O(n*n)
    // SC: O(n*n) + O(n)

    if (ind == 0)
    {
        return n * price[0];
    }
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int notTake = cutRodMem(ind - 1, n, price, dp);
    int take = -1e9;
    int rodlength = ind + 1;
    if (n >= rodlength)
    {
        take = price[ind] + cutRodMem(ind, n - rodlength, price, dp);
    }
    return dp[ind][n] = max(take, notTake);
}
// Tabulation
int cutRodTab(vector<int> &price, int n)
{
    // TC: O(n*n)
    // SC: O(n*n)

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int rod = 0; rod <= n; rod++)
        {
            int notTake = dp[ind - 1][rod];
            int take = -1e9;
            int rodlength = ind + 1;
            if (rod >= rodlength)
            {
                take = price[ind] + dp[ind][rod - rodlength];
            }
            dp[ind][rod] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
// Space Optimization
int cutRodSpc(vector<int> &price, int n)
{
    // TC: O(n*n)
    // SC: O(n)

    vector<int> prev(n + 1, 0), cur(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int rod = 0; rod <= n; rod++)
        {
            int notTake = prev[rod];
            int take = -1e9;
            int rodlength = ind + 1;
            if (rod >= rodlength)
            {
                take = price[ind] + cur[rod - rodlength];
            }
            cur[rod] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[n];
}
int cutRod(vector<int> &price, int n)
{
    // return cutRodRecur(n - 1, n, price);
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return cutRodMem(n - 1, n, price, dp);
    // return cutRodTab(price, n);
    return cutRodSpc(price, n);
}
int main()
{
    vector<int> nums{3, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << "Max Cost: " << cutRod(nums, n);
    return 0;
}