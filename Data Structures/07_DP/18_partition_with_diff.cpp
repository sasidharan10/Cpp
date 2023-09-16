#include <bits/stdc++.h>
using namespace std;
int findWaysSpc(vector<int> &arr, int k)
{
    // TC: O(n*target) + O(n)
    // SC: O(target)
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        prev[arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            int Notpick = prev[target];
            int pick = 0;
            if (arr[ind] <= target)
                pick = prev[target - arr[ind]];
            cur[target] = (pick + Notpick) % mod;
        }
        prev = cur;
    }
    return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    if (totSum - d < 0 || (totSum - d) % 2 != 0)
        return 0;
    int target = (totSum - d) / 2;
    return findWaysSpc(arr, target);
}
int main()
{
    // vector<int> arr{5, 2, 6, 4};
    vector<int> arr{1, 1, 1, 1};
    // int d = 3;
    int d = 0;
    int n = 4;
    cout << "Count of subsets s1 >= s2, with diff d: " << countPartitions(n, d, arr);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628

leetcode: 

Youtube: https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19&pp=iAQB

algorithm: 

*/