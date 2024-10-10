#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int maxWidthRamp3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (maxi > (j - i + 1))
                    break;
                if (nums[i] <= nums[j])
                {
                    maxi = max(maxi, j - i);
                    break;
                }
            }
        }
        return maxi;
    }

    // Using two pointer and prefix
    int maxWidthRamp(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> maxArr(n, 0);
        int tempMax = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            tempMax = max(tempMax, nums[i]);
            maxArr[i] = tempMax;
        }
        int maxi = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            while (j < n && nums[i] <= maxArr[j])
            {
                maxi = max(maxi, j - i);
                j++;
            }
            i++;
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << "Result: " << s.maxWidthRamp(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-width-ramp

Youtube: https://www.youtube.com/watch?v=mcJBhWXel-Y

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Two%20Pointer/Maximum%20Width%20Ramp.cpp

algorithm:

- Brute Force Approach:

- Try all possible combination.

- Optimal Approach:

- We create a maxArray, which stores the max element from ith index to n.
- Then we itearate through both array, using 2 pointer.
- while(nums[i] <= maxArr[j]), we keep moving j forward.
- Once the codition fails, then we dont need to j anymore. so we increment i, and then 
  check with maxArr[j] again.
- We do this, until (j<n), then return the maxi.

*/

/*

962. Maximum Width Ramp

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The
width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in
nums, return 0.

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

Constraints:

2 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 5 * 10^4

*/

/*
************* Java Code **************

    public static int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int[] maxArr = new int[n];
        int tempMax = 0;
        for (int i = n - 1; i >= 0; i--) {
            tempMax = Math.max(tempMax, nums[i]);
            maxArr[i] = tempMax;
        }
        int maxi = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[i] <= maxArr[j]) {
                maxi = Math.max(maxi, j - i);
                j++;
            }
            i++;
        }
        return maxi;
    }

*/