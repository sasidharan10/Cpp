#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - storing indices
    long long countSubarrays2(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> maxIndices;
        int cntMaxi = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxi)
                maxIndices.push_back(i);
            int sz = maxIndices.size();
            if (sz >= k)
            {
                int first_i = maxIndices[sz - k];
                res += first_i + 1;
            }
        }
        return res;
    }

    // Optimal - Sliding Window
    long long countSubarrays(vector<int> &nums, int k)
    {
        // TC: O(2n)
        // SC: O(1)

        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int cntMaxi = 0;
        int i = 0, j = 0;
        long long res = 0;
        while (j < n)
        {
            if (nums[j] == maxi)
                cntMaxi++;
            while (cntMaxi >= k)
            {
                res += n - j;
                if (nums[i] == maxi)
                    cntMaxi--;
                i++;
            }
            j++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 2, 3, 3};
    int k = 2;
    cout << "Result: " << s.countSubarrays(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

Youtube: https://www.youtube.com/watch?v=06VaWkj8e-0

Code Link:

algorithm:

- Optimal Approach:

- using sliding window.

- find maxi, update cntmaxi as we traverse the arr.
- if(cntMaxi >= k) at index j, then adding remaining elements (n - j)
  will form new subarr, which will also satisfy the condition (cntMaxi >= k).
- hence we can find the total subarr that can be formed by adding res+= n - j;
- Now we shrink the arr and check if the condition still satisfies, if yes,
  we keep adding the res.
- Finally return res.

- By storing Maxi indices

- We store maxi indices in maxIndices[].
- if (sz >= k), means, we found a subarr which satisfies (cntMaxi >= k).
- To find the starting maxi index i.e., first_i, we use (sz - k).
- The elements before first_i, can be used to form new subarr which will satisfy
  the condition. Hence there will be (first_i + 1) subarrs can be formed
  by the current window.
- we traverse further, and keep checking the condition, and update the res.

*/

/*

2962. Count Subarrays Where Max Element Appears at Least K Times

You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums 
appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.
 
Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times 
are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.

*/

/*
************* Java Code **************

public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = Math.max(maxi, nums[i]);
        }
        int cntMaxi = 0;
        int i = 0, j = 0;
        long res = 0;
        while (j < n)
        {
            if (nums[j] == maxi)
                cntMaxi++;
            while (cntMaxi >= k)
            {
                res += n - j;
                if (nums[i] == maxi)
                    cntMaxi--;
                i++;
            }
            j++;
        }
        return res;
    }

*/