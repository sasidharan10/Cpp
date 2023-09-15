#include <bits/stdc++.h>
using namespace std;
bool canPartitionUtil(int n, int k, vector<int> &arr)
{
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
    return prev[k];
}
bool canPartition(vector<int> &arr, int n)
{
    // TC: O(n*target) + O(n)
    // SC: O(n*target)

    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }
    if (totSum % 2 != 0)
        return false;
    int target = totSum / 2;
    return canPartitionUtil(n, target, arr);
}

int main()
{
    vector<int> arr{3, 1, 1, 2, 2, 1};
    int n = 6;
    cout << "Find if Partition subset sum is Equal: " << canPartition(arr, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980

leetcode:

Youtube: https://www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16

algorithm: same to previous problem

*/