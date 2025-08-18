#include <bits/stdc++.h>
using namespace std;

// Recursion
int frogJumpRecur(int ind, int k, vector<int> &heights)
{
    if (ind == 0)
        return 0;
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = INT_MAX;
        if (ind - i >= 0)
        {
            temp = frogJumpRecur(ind - i, k, heights) + abs(heights[ind] - heights[ind - i]);
        }
        minJump = min(temp, minJump);
    }
    return minJump;
}

// Memoization
int frogJumpMem(int ind, int k, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = INT_MAX;
        if (ind - i >= 0)
        {
            temp = frogJumpMem(ind - i, k, heights, dp) + abs(heights[ind] - heights[ind - i]);
        }
        minJump = min(temp, minJump);
    }
    return dp[ind] = minJump;
}

// Tabulation
int frogJumpTab(int n, int k, vector<int> &heights)
{
    vector<int> dp(n + 1, 0);
    int minJump = 1e9;
    // for (int ind = n - 1; ind >= k; ind--)
    for (int ind = 1; ind < n; ind++)
    {
        for (int i = 1; i <= k; i++)
        // for (int i = k; i >= 1; i--)
        {
            int temp = 1e9;
            if (ind - i >= 0)
            {
                temp = dp[ind - i] + abs(heights[ind] - heights[ind - i]);
            }
            minJump = min(temp, minJump);
        }
        dp[ind] = minJump;
    }
    return dp[n - 1];
}

// Space Optimization - not needed

int frogJump(int n, int k, vector<int> &heights)
{
    // return frogJumpRecur(n - 1, k, heights);
    vector<int> dp(n, -1);
    // return frogJumpMem(n - 1, k, heights, dp);
    return frogJumpTab(n, k, heights);
}
int main()
{
    // int n = 4;
    // int k = 2;
    // vector<int> heights{10, 20, 30, 10};
    int n = 10;
    int k = 4;
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    cout << "Least Energy spent: " << frogJump(n, k, heights) << endl;
    return 0;
}

/*

link: https://atcoder.jp/contests/dp/tasks/dp_b

leetcode:

Youtube: https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5

algorithm:

*/