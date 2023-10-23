#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}
int main()
{
    int nums[]{10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    cout << "Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459

leetcode:

Youtube:

algorithm:

*/
