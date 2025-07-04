#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int i = 0, j = 0, n = nums.size(), countZeros = 0, ans = INT_MIN;
        while (j < n)
        {
            if (nums[j] == 0)
            {
                countZeros++;
            }
            while (countZeros > k)
            {
                if (nums[i] == 0)
                {

                    countZeros--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << "Max Consecutive Ones: " << s.longestOnes(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/max-consecutive-ones-iii

Youtube: https://www.youtube.com/watch?v=Gl-8HLvV8bc

algorithm:

- Dynamic sliding window
- case 1: if nums[j] == 1, we increase the window size.
- case 2: if nums[j] == 0 but zeroes < k, we can increase the window size
  (can turn those '0's to 1).
- case 3: Now we have encountered 1 extra '0', hence we move the left pointer forward,
  until we eliminate one '0', to make the (zeroes < k).
- We calculate the window size, and update the maxi.

*/

/*

1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of
consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/

/*
************* Java Code **************

public static int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int zeroes = 0;
        int maxi = Integer.MIN_VALUE;
        int i = 0, j = 0;
        int len = 0;
        while (j < n) {
            // case 1
            if (nums[j] == 1) {
                j++;
            }
            // case 2
            else if (nums[j] == 0 && zeroes < k) {
                j++;
                zeroes++;
            }
            // case 3
            else {
                while (nums[i] != 0) {
                    i++;
                }
                i++;
                zeroes--;
            }
            len = j - i;
            maxi = Math.max(maxi, len);
        }
        return maxi;
    }

*/