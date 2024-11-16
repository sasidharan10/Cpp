#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - sliding window and checking if every window is consecutive
    vector<int> resultsArray2(vector<int> &nums, int k)
    {
        // TC: O(n^k)
        // SC: O(n)

        if (k == 1)
            return nums;
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int i = 0, j = k - 1;
        while (j < n)
        {
            bool isConsecutive = true;
            for (int l = i + 1; l <= j; l++)
            {
                if (nums[l] != nums[l - 1] + 1)
                {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive)
                res[i] = nums[j];
            i++;
            j++;
        }
        return res;
    }

    // Optimal - Sliding window and keeping consecutive elements count,
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        // TC: O(n^k)
        // SC: O(n)

        if (k == 1)
            return nums;
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        int consecutiveCnt = 1;
        for (int i = 1; i < k; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
                consecutiveCnt++;
            else
                consecutiveCnt = 1;
        }

        if (consecutiveCnt == k)
            res[0] = nums[k - 1];

        int i = 1, j = k;
        while (j < n)
        {
            if (nums[j] == nums[j - 1] + 1)
                consecutiveCnt++;
            else
                consecutiveCnt = 1;

            if (consecutiveCnt >= k)
                res[i] = nums[j];

            i++;
            j++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 3, 2, 5};
    int k = 3;
    vector<int> ans = s.resultsArray(nums, k);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

Youtube: https://www.youtube.com/watch?v=P1_yXMhqC50

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Find%20the%20Power%20of%20K-Size%20Subarrays%20I.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

3254. Find the Power of K-Size Subarrays I

You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all subarrays of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

Example 1:

Input: nums = [1,2,3,4,3,2,5], k = 3

Output: [3,4,-1,-1,-1]

Explanation:

There are 5 subarrays of nums of size 3:

[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.

Example 2:

Input: nums = [2,2,2,2,2], k = 4

Output: [-1,-1]

Example 3:

Input: nums = [3,2,3,2,3,2], k = 2

Output: [-1,3,-1,3,-1]

Constraints:

1 <= n == nums.length <= 500
1 <= nums[i] <= 10^5
1 <= k <= n

*/

/*
************* Java Code **************

    public static int[] resultsArray(int[] nums, int k) {
        if (k == 1)
            return nums;
        int n = nums.length;
        int[] res = new int[n - k + 1];
        Arrays.fill(res, -1);
        int consecutiveCnt = 1;
        for (int i = 1; i < k; i++) {
            if (nums[i] == nums[i - 1] + 1)
                consecutiveCnt++;
            else
                consecutiveCnt = 1;
        }

        if (consecutiveCnt == k)
            res[0] = nums[k - 1];

        int i = 1, j = k;
        while (j < n) {
            if (nums[j] == nums[j - 1] + 1)
                consecutiveCnt++;
            else
                consecutiveCnt = 1;

            if (consecutiveCnt >= k)
                res[i] = nums[j];

            i++;
            j++;
        }
        return res;
    }

*/