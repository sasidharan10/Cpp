#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - using O(n) space
    int firstMissingPositive(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<bool> mp(n + 1, false); // Track presence of numbers 1 to n

        for (int i = 0; i < n; i++)
        {
            // Mark true only for values in range [1, n]
            if (nums[i] >= 1 && nums[i] <= n)
                mp[nums[i]] = true;
        }

        // Find first number in range [1, n] that is missing
        for (int i = 1; i <= n; i++)
        {
            if (!mp[i])
                return i;
        }

        // If all 1 to n are present, then answer is n+1
        return n + 1;
    }

    // Optimal - using number as index trick (works for problems having numbers 1 to n)
    int firstMissingPositive2(vector<int> &nums)
    {
        // TC: O(3n) = O(n)
        // SC: O(1)

        int n = nums.size();
        bool contains1 = false;

        // Step 1: Normalize invalid numbers and check if 1 exists
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                contains1 = true;
            // Replace out-of-range values (negatives, 0, >n) with 1
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        // If 1 is not present, it's the smallest missing positive
        if (!contains1)
            return 1;

        // Step 2: Mark indices as visited by negating the value at corresponding index
        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]); // Use absolute in case already marked negative
            int ind = num - 1;      // Index = value - 1
            if (nums[ind] > 0)
                nums[ind] = -nums[ind]; // Mark as visited
        }

        // Step 3: First index with positive value means that index+1 is missing
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }

        // If all indices are marked, return n+1
        return n + 1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 4, -1, -2, 1, 5, 16, 0, 2, 0};
    // vector<int> nums{1, 2, 3};
    cout << "Result: " << s.firstMissingPositive(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/first-missing-positive/

Youtube: https://www.youtube.com/watch?v=lyjOwaUEWWQ

algorithm:

Code Link:

- Brute Force Approach:

- Only numbers in the range [1, n] are relevant; ignore others.
- Create a boolean array mp[n+1] to mark the presence of each number.
- Traverse the input and mark mp[nums[i]] = true if in range.
- Return the first index i such that mp[i] == false.
- If all 1 to n exist, answer is n+1.

- Optimal Approach:

- Replace non-positive or out-of-bound numbers with 1.
- Check if 1 is present; if not, return 1.
- For each number val, mark nums[val - 1] as negative to indicate presence.
- The first index i where nums[i] is positive implies i+1 is missing.

*/

/*

41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1

*/

/*
************* Java Code **************

    public static int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean contains1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                contains1 = true;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if (!contains1)
            return 1;

        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);
            int ind = num - 1;
            if (nums[ind] > 0)
                nums[ind] = -nums[ind];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }

*/