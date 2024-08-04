#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - genenrate all subarray sums, then sort and find the sum.
    int rangeSum2(vector<int> &nums, int n, int left, int right)
    {
        // TC: O(n^2) + O(mlogm) where m = n*(n+1)/2 ~= O(n^2).
        // SC: O(m)

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int prefix = 0;
            for (int j = i; j < n; j++)
            {
                prefix += nums[j];
                res.push_back(prefix);
            }
        }
        sort(res.begin(), res.end());
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++)
        {
            ans = (ans + res[i]) % mod;
        }
        return ans;
    }

    // Better - Using min-heap to find all subarray sums.
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        // TC: O(mlogn) where m = n*(n+1)/2 ~= O(n^2).
        // SC: O(n)
        // why logn? because at any moment, there's only n elements present in the min-heap.

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < right; i++)
        {
            int sum = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            // taking the sum of subarrays, in range [left, right]
            if (i >= left - 1)
            {
                ans = (ans + sum) % mod;
            }

            // checking if reached the end of array.
            if (index + 1 < n)
            {
                pq.push({sum + nums[index + 1], index + 1});
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    int n = 4, left = 1, right = 5;
    cout << "Result: " << s.rangeSum(nums, n, left, right) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

- Finding all possible subarray sum, then storing it in an array.
- sort the array and then return the sum from index (left - 1, right - 1).

- Optimal Approach:

- 

*/

/*

1508. Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all
non-empty continuous subarrays from the array and then sorted them in non-decreasing order,
creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in
the new array. Since the answer can be a huge number return it modulo 109 + 7.

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in
non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the
numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.

Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new
array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.

Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50

Constraints:

n == nums.length
1 <= nums.length <= 1000
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2

*/

/*
************* Java Code **************

public static int rangeSum(int[] nums, int n, int left, int right) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < n; i++) {
            pq.offer(new int[] { nums[i], i });
        }
        int ans = 0;
        int mod = 1000000007;
        for (int i = 0; i < right; i++) {
            int sum = pq.peek()[0];
            int index = pq.peek()[1];
            pq.poll();

            // taking the sum of subarrays, in range [left, right]
            if (i >= left - 1) {
                ans = (ans + sum) % mod;
            }

            // checking if reached the end of array.
            if (index + 1 < n) {
                pq.offer(new int[] { sum + nums[index + 1], index + 1 });
            }
        }
        return ans;
    }

*/