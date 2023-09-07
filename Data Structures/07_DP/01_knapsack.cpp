#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        if (n == 0 || W == 0)
            return 0;

        if (W > wt[n])
        {
            return max(val[n] + knapSack(W - wt[n], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else
            return knapSack(W, wt, val, n - 1);
    }
    int knapSackMem(int W, int wt[], int val[], int n, vector<int> &dp)
    {
        if (n == 0 || W == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        if (W >= wt[n])
        {
            return dp[n] = max(val[n] + knapSackMem(W - wt[n], wt, val, n - 1, dp), knapSackMem(W, wt, val, n - 1, dp));
        }
        else
            return dp[n] = knapSackMem(W, wt, val, n - 1, dp);
    }
};
int main()
{
    Solution s;
    int val[]{1, 2, 3};
    int wt[]{4, 5, 1};
    int n = 3;
    int W = 4;
    // cout << "Max Profit: " << s.knapSack(W, wt, val, n - 1);
    vector<int> dp(n + 1, -1);
    cout << "Max Profit: " << s.knapSackMem(W, wt, val, n - 1, dp);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

leetcode: 

Youtube: 

algorithm: 

*/