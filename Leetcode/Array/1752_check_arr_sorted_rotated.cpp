#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    bool check4(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = nums.size();
        vector<int> sorted(n);
        for (int r = 0; r < n; r++)
        {
            int idx = 0;
            for (int i = r; i < n; i++)
            {
                sorted[idx] = nums[i];
                idx++;
            }
            for (int i = 0; i < r; i++)
            {
                sorted[idx] = nums[i];
                idx++;
            }
            bool isSorted = true;
            for (int i = 1; i < n; i++)
            {
                if (sorted[i - 1] > sorted[i])
                {
                    isSorted = false;
                    break;
                }
            }
            if (isSorted)
                return true;
        }
        return false;
    }

    // Brute force - but better
    bool check3(vector<int> &nums)
    {
        // TC: O(nlogn) + O(n^2)
        // SC: O(n)

        int n = nums.size();
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        for (int r = 0; r < n; r++)
        {
            int idx = 0;
            bool isSorted = true;
            for (int i = 0; i < n; i++)
            {
                if (sorted[idx] != nums[(i + r) % n])
                {
                    isSorted = false;
                    break;
                }
                idx++;
            }
            if (isSorted)
                return true;
        }
        return false;
    }

    // Optimal - my approach: finding peak element then checking if its sorted.
    bool check2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int peakIndex = -1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                peakIndex = i - 1;
                break;
            }
        }
        for (int i = peakIndex + 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return false;
        }
        int lastElm = nums[n - 1];
        for (int i = 0; i <= peakIndex; i++)
        {
            if (nums[i] < lastElm)
                return false;
            lastElm = nums[i];
        }
        return true;
    }

    // Optimal - counting no of peak elements
    bool check(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int peak = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                peak++;
            }
        }
        return (peak <= 1) ? true : false;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{3,4,5,1,2};
    vector<int> nums{2, 1, 3, 4};
    cout << "Result: " << s.check(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

Youtube: https://www.youtube.com/watch?v=-o4vCUI7jmk

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Check%20if%20Array%20Is%20Sorted%20and%20Rotated.cpp

algorithm:

- Brute Force Approach:

- generate all rotated array combo, then check if its equal to the given array.

- Optimal Approach:

- My approach.
- FInd the peak index. From the next index to n, check if the array is sorted in non-decreasing order.
- Then check if the array is increasing from 0 to peakIndex. 
- We do the check for nums[n-1] (or lastElm) with nums[0] because, of this edge case  [2, 1, 3, 4].

- The other optimal approach is to find the no of peak elements, if its > 1, then return false.
- Again we do a check with nums[n-1] (or lastElm) with nums[0] for the above mentioned edge case.

*/

/*

1752. Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated
some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length],
where % is the modulo operation.

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

/*
************* Java Code **************

    // Brute force
    public boolean check(int[] nums) {
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        for (int r = 0; r < n; r++) {
            int idx = 0;
            boolean isSorted = true;
            for (int i = 0; i < n; i++) {
                if (sorted[idx] != nums[(i + r) % n]) {
                    isSorted = false;
                    break;
                }
                idx++;
            }
            if (isSorted)
                return true;
        }
        return false;
    }

    // Optimal:
    public boolean check(int[] nums) {
        int n = nums.length;
        int peak = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                peak++;
            }
        }
        return (peak <= 1) ? true : false;
    }


*/