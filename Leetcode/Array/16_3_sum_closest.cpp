#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - Gives TLE
    int threeSumClosest2(vector<int> &nums, int target)
    {
        // TC: O(n^3)
        // SC: O(1)

        int n = nums.size();
        int closestSum = 1e9;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(target - sum) < abs(target - closestSum))
                        closestSum = sum;
                }
            }
        }
        return closestSum;
    }
    int threeSumClosest(vector<int> &nums, int target)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(1)
        
        int n = nums.size();
        int closestSum = 1e9;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(target - sum) < abs(target - closestSum))
                    closestSum = sum;

                if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return closestSum;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    cout << "Result: " << s.threeSumClosest(nums, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/3sum-closest/

Youtube: https://www.youtube.com/watch?v=hGLjwiPRh0U

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Two%20Pointer/3Sum%20Closest.cpp

algorithm:

- Brute Force Approach:

- Find all 3 number combinations.

- Optimal Approach:

- sorting and using 2 pointer

*/

/*

16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that 
the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

*/

/*
************* Java Code **************

    public static int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int closestSum = 1000000000;
        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (Math.abs(target - sum) < Math.abs(target - closestSum))
                    closestSum = sum;

                if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return closestSum;
    }

*/