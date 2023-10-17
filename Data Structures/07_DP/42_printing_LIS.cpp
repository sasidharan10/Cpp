#include <bits/stdc++.h>
using namespace std;
// Space Optimization
vector<int> longestIncreasingSubsequenceSpc(int arr[], int n)
{
    vector<int> dp(n, 0), hash(n, 0);
    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> longestIncreasingSubsequence(int arr[], int n)
{
    return longestIncreasingSubsequenceSpc(arr, n);
}
int main()
{
    int nums[]{5, 4, 11, 1, 16, 8};
    int n = 6;
    vector<int> ans = longestIncreasingSubsequence(nums, n);
    cout << "Longest Increasing Subsequence: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode:

Youtube: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44

algorithm:

*/