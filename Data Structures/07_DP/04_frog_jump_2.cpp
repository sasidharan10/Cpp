#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
int frogJumpRecur(int n, int k, vector<int> &heights)
{
    if (n == 0)
        return 0;
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = INT_MAX;
        if (n - i >= 0)
        {
            temp = frogJumpRecur(n - i, k, heights) + abs(heights[n] - heights[n - i]);
        }
        minJump = min(temp, minJump);
    }
    return minJump;
}
// Memoization
int frogJumpMem(int n, int k, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = INT_MAX;
        if (n - i >= 0)
        {
            temp = frogJumpMem(n - i, k, heights, dp) + abs(heights[n] - heights[n - i]);
        }
        minJump = min(temp, minJump);
    }
    return dp[n] = minJump;
}
// Tabulation not working
int frogJumpTab(int N, int k, vector<int> &heights)
{
    vector<int> dp(N + k, 0);
    int minJump = 1e9;
    // for (int n = N - 1; n >= k; n--)
    for (int n = k; n < N + 1; n++)
    {
        for (int i = 1; i <= k; i++)
        // for (int i = k; i >= 1; i--)
        {
            int temp = 1e9;
            if (n - i >= 0)
            {
                temp = dp[n - i] + abs(heights[n] - heights[n - i]);
            }
            minJump = min(temp, minJump);
        }
        dp[n] = minJump;
    }
    cout << endl;
    for (auto &&i : dp)
    {
        cout << i << " ";
    }

    return dp[N];
}
int frogJump(int n, int k, vector<int> &heights)
{
    // return frogJumpRecur(n - 1, k, heights);
    vector<int> dp(n, -1);
    return frogJumpMem(n - 1, k, heights, dp);
    // return frogJumpTab(n, k, heights);
}
int main()
{
    // int n = 4;
    // int k = 2;
    // vector<int> heights{10, 20, 30, 10};
    int n = 10;
    int k = 4;
    vector<int> heights{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    cout << "Least Energy spent: " << frogJump(n, k, heights);
    return 0;
}

/*

link: https://atcoder.jp/contests/dp/tasks/dp_b

leetcode:

Youtube: https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5

algorithm:

*/