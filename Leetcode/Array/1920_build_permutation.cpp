#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    vector<int> buildArray2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> res; // result array to store the final values

        for (int i = 0; i < n; i++)
        {
            int idx = nums[i];   // get the index from nums[i]
            int elm = nums[idx]; // fetch element at that index
            res.push_back(elm);  // add it to result array
        }

        return res;
    }

    // Optimal - storing 2 numbers in a single element using math.
    vector<int> buildArray(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        // First pass: encode new value along with old value into nums[i]
        for (int i = 0; i < n; i++)
        {
            int oldVal = nums[i];            // current value at nums[i]
            int newVal = nums[oldVal] % n;   // fetch new value (use % n to avoid already encoded numbers)
            nums[i] = oldVal + (newVal * n); // store both old and new in same place
        }

        // Second pass: decode and keep only the new values
        for (int i = 0; i < n; i++)
        {
            int newVal = nums[i] / n; // integer division gives the new value
            nums[i] = newVal;         // update nums[i] with the new value
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 2, 1, 5, 3, 4};
    vector<int> ans = s.buildArray(nums);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/build-array-from-permutation

Youtube: https://www.youtube.com/watch?v=0Q7m9VFCrUI

Code Link:

algorithm:

- Brute Force Approach:

- Create a new result array.
- For each index i, look at nums[i] (say it’s idx).
- Append nums[idx] into the result.
- Requires extra space O(n) for the new array.
- Simple and intuitive.

- Optimal Approach:

- Goal: do it in-place without extra array.
- Store both old value and new value in one integer:
    - nums[i] = oldVal + (newVal * n)
- Why this works:
    - Since all values are < n, multiplying newVal by n shifts it away.
    - % n helps extract original values when needed.
- After encoding all values, divide each by n to extract the new values.
- Saves space: O(1) extra space.

*/

/*

1920. Build Array from Permutation

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]]
for each 0 <= i < nums.length and return it.
A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]

Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
The elements in nums are distinct.

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?

*/

/*
************* Java Code **************

    public int[] buildArray(int[] nums) {
        // TC: O(n)
        // SC: O(1)
        int n = nums.length;

        // First pass: encode both values in each element
        for (int i = 0; i < n; i++) {
            int oldVal = nums[i];
            int newVal = nums[oldVal] % n;
            nums[i] = oldVal + (newVal * n);
        }

        // Second pass: extract the new values
        for (int i = 0; i < n; i++) {
            int newVal = nums[i] / n;
            nums[i] = newVal;
        }
        return nums;
    }

*/