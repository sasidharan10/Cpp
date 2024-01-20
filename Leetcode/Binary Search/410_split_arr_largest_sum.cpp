#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canSplit(int targetSum, vector<int> &nums, int n, int k)
    {
        int curSum = 0, curSplit = 1;
        for (int i = 0; i < n; i++)
        {
            if (curSum + nums[i] <= targetSum)
            {
                curSum += nums[i];
            }
            else
            {
                curSum = nums[i];
                curSplit++;
            }
        }
        return curSplit == k;
    }
    // Brute Force
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mini = *max_element(nums.begin(), nums.end());
        int maxi = accumulate(nums.begin(), nums.end(), 0);
        int i = 0;
        for (i = mini; i <= maxi; i++)
        {
            if (canSplit(i, nums, n, k))
                return i;
        }
        return i;
    }
    // Optimal
    int splitArray2(vector<int> &nums, int k)
    {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int i = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (canSplit(mid, nums, n, k))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{7, 2, 5, 10, 8};
    // int k = 2;
    vector<int> nums{1, 4, 4};
    int k = 3;
    cout << "Result: " << s.splitArray(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/split-array-largest-sum/

Youtube:

algorithm:

*/

/*

410. Split Array Largest Sum

Given an integer array nums and an integer k, split nums into k non-empty
subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest
sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest
sum among the two subarrays is only 9.

*/