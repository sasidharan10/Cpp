#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    int k = totSum;
    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    int mini = 1e9;
    for (int i = 0; i <= k / 2; i++)
    {
        if (prev[i])
        {
            int s1 = i;
            mini = min(mini, abs(s1 - (totSum - s1)));
        }
    }
    return mini;
}

int main()
{
    vector<int> arr{8, 6, 5};
    int n = 3;
    cout << "Min Partition subset difference: " << minSubsetSumDifference(arr, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

leetcode: 

Youtube: https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17

algorithm: 

*/