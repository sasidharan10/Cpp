#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)
        
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        res = min(res, nums[n - 4] - nums[0]);
        res = min(res, nums[n - 3] - nums[1]);
        res = min(res, nums[n - 2] - nums[2]);
        res = min(res, nums[n - 1] - nums[3]);
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 5, 0, 10, 14};
    cout << "Result: " << s.minDifference(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

Youtube: https://www.youtube.com/watch?v=CHxya52oxCM

Code Link:

algorithm:

- Optimal Approach:

- We need to make the difference between mini and maxi element as
  minimum as possible, by changing any 3 elements in the array.
- hence we need to make changes in those elements, which will have impact in the final result.
- By making the mini bigger, and making maxi smaller, to reduce the gap between mini and maxi.
- Hence we sort the array, and pick first 3 and last 3 elements.
- there are only 4 options to reduce the gap, by making changes in
  - first 3 elements
  - first 2 elements and last 2
  - first element and last 2
  - last e elements.
- Examples to understand:
  - [0, 0, 1, 1, 7, 10, 14] => [0, 0, 1, 1, 1, 1, 1] => diff = (1 - 0) => 1 (changing last 3 elm).
  - [0, 1, 1, 4, 6, 6, 6] => [4, 4, 4, 4, 6, 6, 6] => diff = (6 - 4) => 2 (changing first 3 elm).
- So we try all 4 options, and find the smallest diff, and return it.

*/

/*

1509. Minimum Difference Between Largest and Smallest Value in Three Moves

You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums after performing
at most three moves.

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.

Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/

/*
************* Java Code **************

public int minDifference(int[] nums) {
        int n = nums.length;
        if (n <= 4)
            return 0;
        Arrays.sort(nums);
        int res = Integer.MAX_VALUE;
        res = Math.min(res, nums[n - 4] - nums[0]);
        res = Math.min(res, nums[n - 3] - nums[1]);
        res = Math.min(res, nums[n - 2] - nums[2]);
        res = Math.min(res, nums[n - 1] - nums[3]);
        return res;
    }

*/