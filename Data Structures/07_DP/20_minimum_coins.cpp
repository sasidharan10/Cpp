#include <bits/stdc++.h>
using namespace std;
// Recursion
int minimumElementsRecur(int ind, int target, vector<int> &arr)
{
    // TC: greater than O(2^n), exponentially
    // SC: O(target)

    if (ind == 0)
    {
        if (target % arr[ind] == 0)
            return target / arr[ind];
        return 1e9;
    }
    int notTake = 0 + minimumElementsRecur(ind - 1, target, arr);
    int take = 1e9;
    if (arr[ind] <= target)
        take = 1 + minimumElementsRecur(ind, target - arr[ind], arr);
    return min(take, notTake);
}
// Memoization
int minimumElementsMem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // TC: O(n * target)
    // SC: O(n * target) + O(target)

    if (ind == 0)
    {
        if (target % arr[ind] == 0)
            return target / arr[ind];
        return 1e9;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notTake = 0 + minimumElementsMem(ind - 1, target, arr, dp);
    int take = 1e9;
    if (arr[ind] <= target)
        take = 1 + minimumElementsMem(ind, target - arr[ind], arr, dp);
    return dp[ind][target] = min(take, notTake);
}
// Tabulation
int minimumElementsTab(vector<int> &arr, int x)
{
    // TC: O(n * target)
    // SC: O(n * target)

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int t = 0; t <= x; t++)
    {
        if (t % arr[0] == 0)
            dp[0][t] = t / arr[0];
        else
            dp[0][t] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int notTake = 0 + dp[ind - 1][target];
            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
            dp[ind][target] = min(take, notTake);
        }
    }
    return dp[n - 1][x];
}
// Space Optimization
int minimumElementsSpc(vector<int> &arr, int x)
{
    // TC: O(n * target)
    // SC: O(target)

    int n = arr.size();
    vector<int> prev(x + 1, 0), cur(x + 1, 0);
    for (int t = 0; t <= x; t++)
    {
        if (t % arr[0] == 0)
            prev[t] = t / arr[0];
        else
            prev[t] = 1e9;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int notTake = 0 + prev[target];
            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
            cur[target] = min(take, notTake);
        }
        prev = cur;
    }
    return prev[x];
}
int minimumElements(vector<int> &num, int x)
{
    int ans;
    // ans = minimumElementsRecur(num.size() - 1, x, num);
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, -1));
    // ans = minimumElementsMem(num.size() - 1, x, num, dp);
    // ans = minimumElementsTab(num, x);
    ans = minimumElementsSpc(num, x);
    if (ans < 1e9)
        return ans;
    else
        return -1;
}
int main()
{
    vector<int> nums{1, 2, 3};
    int target = 7;
    int n = 3;
    cout << "Minimum no of coins: " << minimumElements(nums, target);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091

leetcode: https://leetcode.com/problems/coin-change-ii/

Youtube: https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22

algorithm:

*/