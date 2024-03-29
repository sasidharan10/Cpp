#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute - Accpeted
    int numSubarrayProductLessThanK2(vector<int> &nums, int k)
    {
        // TC: O(n^2)
        // SC: O(1)

        if (k == 0 || k == 1) // nums[i] range = [1, 1000]
            return 0;

        int n = nums.size();
        int prod = 1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > k) // prod will definetly be bigger, hence we ignore
                continue;
            for (int j = i; j < n; j++)
            {
                prod *= nums[j];
                if (prod < k)
                    count++;
                // prod already exceeds k, hence no need to compute further in that sub-array
                if (prod > k)
                    break;
            }
            prod = 1;
        }
        return count;
    }

    // Optimal - Sliding window
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // TC: O(2n)
        // SC: O(1)

        if (k == 0 || k == 1) // nums[i] range = [1, 1000]
            return 0;
        int n = nums.size();
        int count = 0;
        int prod = 1;
        int i = 0, j = 0;
        while (j < n)
        {
            prod *= nums[j];
            while (prod >= k)
            {
                prod /= nums[i];
                i++;
            }
            // finding  no of subarrays in sliding window
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums{10, 5, 2, 6};
    int k = 100;
    cout << "Subarray Product Less Than K: " << s.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/subarray-product-less-than-k/

Youtube: https://www.youtube.com/watch?v=9fmKB1F1pEE

Code Link:

algorithm:

- Brute Force Approach:

- Traverse all subarrays and check if the product < k.
- if the current prod of subarray exceeds k, then we can break the loop, and check
  for the next subarray.

- Optimal Approach:

- Using sliding window.
- As we traverse the array, if(prod >= k), then we keep on shrinking the arr from
  the left, until the condition fails.
- Now, to find the no of subarrays, that can be generated from i to j is:
  (j - i + 1). Note that, this technique will only work in case of sliding window
  problem, where we can find the total no of new subarrays that can be generated,
  after adding 1 new element to the array.
- Ex: arr = [2, 7, 4] => {[2], [7], [4], [2, 7], [7, 4]} = 5 sub-arrays.
- new arr = [2, 7, 4, 3] => 5 + {[2, 7, 4, 3], [2, 7, 4], [2, 7], [3]} = 9 sub-arrays.
- here after adding a new element, the total no of sub-arrays = 5 + 4 = 9;

*/

/*

713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of
contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

*/

/*
************* Java Code **************

public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0 || k == 1)
            return 0;
        int n = nums.length;
        int count = 0;
        int prod = 1;
        int i = 0, j = 0;
        while (j < n)
        {
            prod *= nums[j];
            while (prod >= k)
            {
                prod /= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }

*/